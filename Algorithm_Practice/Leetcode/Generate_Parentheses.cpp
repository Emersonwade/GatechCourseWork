#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define ARRAY_NUMBER 12
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
 */

void getresultVector(string currentString, int maxNumber, vector<string> &resultVector, int lbNum, int templbNum)
{
    if(currentString.length() == maxNumber){
        resultVector.push_back(currentString);
        return;
    }

    if(templbNum > 0 && lbNum < maxNumber / 2){
        getresultVector((currentString + "("), maxNumber, resultVector, lbNum + 1, templbNum + 1);
        getresultVector((currentString + ")"), maxNumber, resultVector, lbNum, templbNum - 1);
    }
    else if(lbNum >= maxNumber / 2){
        getresultVector((currentString + ")"), maxNumber, resultVector, lbNum, templbNum - 1);
    }
    else
        getresultVector((currentString + "("), maxNumber, resultVector, lbNum + 1, templbNum + 1);
}

int main(int argc, char const *argv[])
{
    int n;
    string rString = "";
    vector<string>resultVector;
    cout << "PLS input the number of pairs" << endl;
    cin >> n;

    getresultVector(rString, n * 2, resultVector, 0, 0);

    for(vector<string>::iterator i = resultVector.begin(); i != resultVector.end(); i ++){
        cout << *i << endl;
    }

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

