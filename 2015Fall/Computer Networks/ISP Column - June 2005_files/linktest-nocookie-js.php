
// GPLv3
// : ipprototest.js 27701 2011-01-26 15:21:50Z eaben $
// 2011 Hacked on by Byron Ellacott, APNIC 
// 2011 Hacked on by George Michaelson, APNIC 
// Written by Emile Aben, RIPE NCC
// Code inspired by Sander Steffann's IPv6test at http://v6test.max.nl/
(function() {
   var __ipprototest;

   IPProtoTest = function (opts) {
      if ( this instanceof IPProtoTest ) {
         this._version = '10e';
         this._done = false;
         this.userId          = '6';
         this.timeout         = 10000; // 10 seconds
         this.noCheckInterval = 86400000; // 1 day
         this.domainSuffix    = 'potaroo.net';
         this.testSet         = ['r6.td','rd.td','r4.td'];
         this.testSetLen      = this.testSet.length; // shortcut
	 this.randomize       = false;	// disable shuffling
	 this.dotunnels       = false;	// disable tunnel testing
	 this.domore          = true;	// disable tunnel testing
	 this.dov6literal     = true;	// disable tunnel testing
	 this.dov6dns         = true;	// disable tunnel testing
	 this.docookies       = false;	// enable cookie time testing
         this.sampling        = 1;	// sampling frequency. 1 == disable
					// eg 2 == 50% 20 == 5% 100 == 1%

         this._testsComplete = 0;
         this._now = new Date(); // keep track of init-time
         this._testTime = this._now.getTime();
         this._cookieExpire = new Date(this._testTime + this.noCheckInterval );
         this._testId = Math.floor(Math.random()*Math.pow(2,31));

         this._result = {};
         // sets this._cookie_last_run etc. vars
         // and set results from previous run (if available)
         this.parseCookies();
         //TODO compare the testset to set tested in cookies?

         // override defaults
         if ( opts instanceof Object) {
            for ( prop in opts ) {
               //safeguard is now done in the IPProtoTest(opt) call at the end of this file
               this[prop] = opts[prop];
            }

	    if ( this.dov6dns ) { 
		this.testSet.push('rd.t6'); 
	    }
	    if ( this.dov6literal ) { 
		this.testSet.push('v6lit'); 
	    }
	    if ( this.dotunnels ) { 
		this.testSet.push('v6stf'); 
		this.testSet.push('v6ter'); 
	    }
	    if ( this.domore ) { 
		this.testSet.push('rd.td'); 
		this.testSet.push('r6.td'); 
	    }
	    this.testSetLen = this.testSet.length; 
	    if ( this.randomize ) { this.shuffle( this.testSet ); }
         } 

         // make object accessible for callbacks
         __ipprototest = this;

         // determine if tests need to be done
         if ( !this.docookies || !this._cookie_last_run ) {
            if ( this.sampling > 1 && Math.random() > 1/this.sampling ) {
               // not running test, but setting the cookie
               if (this.docookies) this.setCookie('__ipprototest_last_run',this._testTime);
               return this;
            }  else {
               this.startTest();
            }
         } 
         return this;
      } else 
         return new IPProtoTest(opts);
   };
   // public functions

   IPProtoTest.prototype.doGAQ=function() {
      var _gaq = window._gaq || []; // assuming google default
      if (this.GAQ instanceof Object) { // .. but allow override
         _gaq = this.GAQ;
      } 
      //TODO document this
      var ipv4 = this._result.r4td ? 'yes' : 'no';
      var ipv6 = this._result.r6td ? 'yes' : 'no';
      var dual = this._result.rdtd ? 'yes' : 'no';
      if (this.dov6dns) {
       var v6dns = this._result.rdt6 ? 'yes' : 'no';
      }
      if (this.dov6literal) {
       var v6lit = this._result.v6lit ? 'yes' : 'no';
      }

      if (this.dotunnels) {
       var v6stf = this._result.v6stf ? 'yes' : 'no';
       var v6ter = this._result.v6ter ? 'yes' : 'no';
      }

      var summary = ((ipv4  == 'yes' ?  1 : 0) +
		     (ipv6  == 'yes' ?  2 : 0) +
		     (dual  == 'yes' ?  4 : 0));
      if (this.dov6dns) {
	 summary += ((v6dns == 'yes' ?  8 : 0));
      }
      if (this.dov6literal) {
	 summary += ((v6lit == 'yes' ? 16 : 0));
      }

      if (this.dotunnels) {
	 summary += ((v6stf == 'yes' ? 32 : 0) +
	 	     (v6ter == 'yes' ? 64 : 0));
      }

      // Normalize v4val to 0 if the v4 test fails.
      // Normalize all other test times to relative to v4, if v4 worked
      // If a test fails, set to zero.
      // If v4 failed, set all tests to zero.
      // This ensures zero cases, and no v4 do not contribute to avg times 
      var v4val = this._result.r4td ? this._result.r4td : 0;
      var v6val = this._result.r6td ? (this._result.r4td ? (this._result.r6td - v4val) : 0) : 0;
      var duval = this._result.rdtd ? (this._result.r4td ? (this._result.rdtd - v4val) : 0) : 0;
      if (this.dov6dns) {
       var dnval = this._result.v6dns ? (this._result.r4td ? (this._result.v6dns - v4val) : 0) : 0;
      }
      if (this.dov6literal) {
       var lival = this._result.v6lit ? (this._result.r4td ? (this._result.v6lit - v4val) : 0) : 0;
      }

      if (this.dotunnels) {
       var stval = this._result.v6stf ? (this._result.r4td ? (this._result.v6stf - v4val) : 0) : 0;
       var teval = this._result.v6ter ? (this._result.r4td ? (this._result.v6ter - v4val) : 0) : 0;
      }

      if (this.domore) {
       var stval = this._result.rd.td ? (this._result.r4td ? (this._result.td.td - v4val) : 0) : 0;
       var teval = this._result.r6.td ? (this._result.r4td ? (this._result.r6.td - v4val) : 0) : 0;
      }

      _gaq.push(['_trackEvent', 'ipprototest', 'ipv4:' + ipv4, 'Tested', 0]);
      _gaq.push(['_trackEvent', 'ipprototest', 'ipv6:' + ipv6, 'Tested', v6val]);
      _gaq.push(['_trackEvent', 'ipprototest', 'dual:' + dual, 'Tested', duval]); 
      if (this.dov6dns) {
       _gaq.push(['_trackEvent', 'ipprototest', 'v6lit:' + v6lit, 'Tested', lival]); 
      }
      if (this.dov6literal) {
       _gaq.push(['_trackEvent', 'ipprototest', 'v6dns:' + v6dns, 'Tested', dnval]); 
      }

      if (this.dotunnels) {
       _gaq.push(['_trackEvent', 'ipprototest', 'v6stf:' + v6stf, 'Tested', stval]); 
       _gaq.push(['_trackEvent', 'ipprototest', 'v6ter:' + v6ter, 'Tested', teval]); 
      }

      // push summary line, this users testset.
      _gaq.push(['_trackEvent', 'ipprototest', 'summary:' + summary]); 
   };


   IPProtoTest.prototype.onFinishInit=function() {
         if ( this.GAQ ) { // do Google analytics
            this.doGAQ();
         }
   };

   IPProtoTest.prototype.finishTest=function() {
      // cancel the timeout
      clearTimeout( __ipprototest._timeoutEvent );
      if (! __ipprototest._done ) {
         // report back results
         var pfx = __ipprototest.getTestPfx();
         for (var t_idx in __ipprototest.testSet) {
            var test = __ipprototest.testSet[t_idx];
            test = test.replace(/\./g,'');
            pfx += [ 
               'z',
               test , 
               '-' , 
               __ipprototest._result[ test ] ? 
                  __ipprototest._result[ test ] :
                  'null',
               '.'
            ].join('');
         }
         var imgURL = [
            'http://',
            pfx,
            'results.',
            __ipprototest.domainSuffix,
            '/1x1.png?',
            pfx
         ].join('');
         var req=document.createElement('img');
         req.src = imgURL; // loads it

         if(__ipprototest.docookies) __ipprototest.setCookie('__ipprototest_last_run', __ipprototest._testTime);
         // do all the stuff that needs to be done when
         // results are in
         __ipprototest.onFinishInit();
         __ipprototest._done = true;

	 // if there is a callback function, invoke it
	 if ( __ipprototest.callback instanceof Function ) __ipprototest.callback(__ipprototest._result);
      } 
   };

   IPProtoTest.prototype.getTestPfx = function() {
      return [
         't', this.timeout, '.',
         'u', this._testTime , '.',
         's', this._testId , '.',
         'i', this.userId , '.',
         'v', this._version , '.'
      ].join('');
   };

   IPProtoTest.prototype.startTest = function() {
         var testPfx = this.getTestPfx();
         var testPath='/1x1.png?'+testPfx;
         for(var i=0;i<this.testSetLen;i++) {
            var subId = this.testSet[i];
	    this._result[subId.replace(/\./g,'')] = false;
	    if (subId == 'v6lit') {
             this.httpFetchImg(
               'http://[2401:2000:6660::f003]'+testPath+subId,
               '__ipprototest_'+subId.replace(/\./g,'') );
	    } else if (subId == 'v6stf') {
             this.httpFetchImg(
               'http://[2401:2000:6660::f00a]'+testPath+subId,
               '__ipprototest_'+subId.replace(/\./g,'') );
	    } else if (subId == 'v6ter') {
             this.httpFetchImg(
               'http://[2401:2000:6660::f00b]'+testPath+subId,
               '__ipprototest_'+subId.replace(/\./g,'') );
	    } else {
             this.httpFetchImg(
               'http://'+testPfx+subId+'.'+this.domainSuffix+testPath+subId,
               '__ipprototest_'+subId.replace(/\./g,'') );
	    }
         }
         this._timeoutEvent = setTimeout( this.finishTest, this.timeout );
   };

   // Fisher-Yates Shuffle  
   IPProtoTest.prototype.shuffle=function( list ) {
      var i = list.length;
      if ( ! i ) return false;
      while ( --i ) {
         var j = Math.floor( Math.random() * ( i + 1 ) );
         var tmp_i = list[i];
         var tmp_j = list[j];
         list[i] = tmp_j;
         list[j] = tmp_i;
      }
      return true;
   };

   // cookie stuff
   IPProtoTest.prototype.setCookie=function(key,value) {
      document.cookie = key+'='+value+';expires='+this._cookieExpire.toUTCString()+';path=/';
   };

   IPProtoTest.prototype.parseCookies=function() {
      var _all = document.cookie.split(';');
      for(var i=0, len=_all.length;i<len;i++) {
         var _tmp =_all[i].split('=');
         var ckName=_tmp[0].replace(/^\s+|\s+$/g,'');
         var res_match;
         if(ckName=='__ipprototest_last_run'){
            this._cookie_last_run = parseInt(unescape(_tmp[1].replace(/^\s+|\s+$/g,'')),10);
         }
      }
   };

   function __ipprototest_onload(el) {
      // note to self : this = the img element, not the proto
      this._duration = new Date().getTime() - this._start;
      __ipprototest._testsComplete++;
      var res_match = this.name.match(/^__ipprototest_(\w+)$/);
      if ( res_match[1] ) { // codes like 'rdtd'
         __ipprototest._result[res_match[1]] = this._duration;
      }
      if (__ipprototest._testsComplete >= __ipprototest.testSetLen) {
         __ipprototest.finishTest();
      }
   }

   // inspired by gih_ajax-function by Geoff Huston, George Michaelson, Byron Ellacott (APNIC)
   IPProtoTest.prototype.httpFetchImg=function( url, name ) {
      var req=document.createElement('img');
      req.name = name;
      req._start = new Date().getTime(); 
      req.onload = __ipprototest_onload;
      req.src = url;
   };
})();

// initialize variables and structs to avoid null ref bugs
var ipproto_user = ipproto_user || 'anon';
var ipproto_opts = ipproto_opts || {};

// if we have been correctly initialized for google analytics setup by the user...
 
// the set of externally defined variables we will accept
// userID takes the ipproto_user variable by default, 
//  or the value passed in array externally if provided
// defaults shown below.
var opts = {
     'docookies'	: false,		// test based on noCheckInterval in cookie
     'dov6dns'		: true,		// test v6 dns to a dual-stack URL 
     'dov6literal'	: true,		// test a v6 literal URL
     'dotunnels'	: false,	// test for 6to4 and teredo tunnels
     'domore'	        : true,	        // test for v6 using alt server
     'randomize'	: false,	// by default, sorted test order
     'noCheckInterval'	: 86400000,	// interval to test on, if docoookies is true
     'sampling'		: 1,		// 1/sampling eg sampling=4 1/4th tested
     'userId'		: ipproto_user, // what to log in the collector website as
     'callback'		: function (results){}, 	// prototype function to receive callback of results
     'GAQ'		: false     	// hook into google analytics
};
 
if ( ipproto_opts instanceof Object ) {
 	// for the list we know, if its in the externally set object, map it in.
 	for ( prop in opts ) {
 		if (prop in ipproto_opts) { opts[prop] = ipproto_opts[prop]; }
 	}
}

var ippt = IPProtoTest(opts);

