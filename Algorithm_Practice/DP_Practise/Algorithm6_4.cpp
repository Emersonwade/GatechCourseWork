#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define STRINGLENGTH 19
/*
Youaregivenastringofncharacterss[1...n],whichyoubelievetobeacorruptedtextdocument in which all punctuation has vanished (so that it looks something like “itwasthebestoftimes...”). You wish to reconstruct the document using a dictionary, which is available in the form of a Boolean function dict(·): for any strin􏰉g w,
true if w is a valid word false otherwise.
(a) Give a dynamic programming algorithm that determines whether the string s[·] can be reconstituted as a sequence of valid words. The running time should be at most O(n2), assuming calls to dict take unit time.
(b) In the event that the string is valid, make your algorithm output the corresponding se- quence of words.
 */
 
bool dict(vector<string>stringDict, string checkString)
{
    //cout << checkString << endl;
    for(vector<string>::iterator i = stringDict.begin(); i != stringDict.end(); i ++) {
        if ((*i) == checkString)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string inputString = "itwasthebestoftimes";
    bool resultArray[STRINGLENGTH + 1];
    vector<string> dictVector;
    dictVector.push_back("it");
    dictVector.push_back("was");
    dictVector.push_back("times");
    dictVector.push_back("of");
    dictVector.push_back("best");
    dictVector.push_back("the");

    resultArray[0] = true;
    for(int i = 1; i < STRINGLENGTH + 1; i ++){
        bool tempResult = false;
        for(int j = 1; j < i; j ++){
            tempResult = tempResult || (resultArray[j - 1] && dict(dictVector, inputString.substr(j - 1, i - (j - 1))));
        }
        resultArray[i] = tempResult;
    }

    for(int i = 0; i < STRINGLENGTH + 1; i ++){
        cout << resultArray[i] << " ";
    }
    return 0;
}

