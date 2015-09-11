#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */

int main(int argc, char const *argv[])
{
    string a, b;
    cout << "PLS input two strings" << endl;
    cin >> a >> b;
    string result = "";
    int aLength = a.length(), bLength = b.length();
    int lLoop;
    string l, s;
    if(aLength >= bLength){
        lLoop = aLength;
        l = a;
        string zero(aLength - bLength,'0');
        s = zero + b;
    }
    else{
        lLoop = bLength;
        l = b;
        string zero(bLength - aLength,'0');
        s = zero + a;
    }

    int incr = 0;
    for(int i = 0; i < lLoop; i ++){
        int templ = l[lLoop - 1 - i] - '0';
        int temps = s[lLoop - 1 - i] - '0';
        if(templ + temps + incr == 3){
            incr = 1;
            result = to_string(1) + result;
        }
        else if(templ + temps + incr == 2){
            incr = 1;
            result = to_string(0) + result;
        }
        else if(templ + temps + incr == 0){
            incr = 0;
            result = to_string(0) + result;
        }
        else{
            incr = 0;
            result = to_string(1) + result;
        }
    }
    if(incr == 1)
        result = to_string(1) + result;

    cout << result << endl;
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
 Some other's solution which only cost half of mine and o(1) space.
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length(), c = 0, i, j;
        if (m < n) return addBinary(b, a);
        for (i = m - 1, j = n - 1; j >= 0; i--, j--) {
            int ad = a[i] - '0', bd = b[j] - '0';
            a[i] = (ad ^ bd ^ c) + '0';
            c = (ad + bd + c >= 2);
        }
        for (; i >= 0; i--) {
            int ad = a[i] - '0';
            a[i] = (ad ^ c) + '0';
            c = (ad + c >= 2);
        }
        if (c) a = '1' + a;
        return a; 
    }
};
 */

