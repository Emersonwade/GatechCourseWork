#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 */

bool isInterleave(string s1, string s2, string s3) {
    if(s1.length() + s2.length() != s3.length())
        return false;
    
    bool **resultTable = new bool* [s1.length() + 1];
    
    for(int i = 0; i <= s1.length(); i ++){
        resultTable[i] = new bool[s2.length() + 1];
    }
    
    resultTable[0][0] = true;
    for(int i = 1; i <= s1.length(); i ++){
        resultTable[i][0] = (s1[i - 1] == s3[i - 1]) && resultTable[i - 1][0]; 
    }
    for(int j = 1; j <= s2.length(); j ++){
        resultTable[0][j] = (s2[j - 1] == s3[j - 1]) && resultTable[0][j - 1]; 
    }
    
    for(int i = 1; i <= s1.length(); i ++){
        for(int j = 1; j <= s2.length(); j ++){
            if(s3[i + j - 1] != s1[i - 1] && s3[i + j - 1] != s2[j - 1]){
                resultTable[i][j] = false;
            }
            else if(s3[i + j - 1] == s1[i - 1] && s3[i + j - 1] == s2[j - 1]){
                resultTable[i][j] = resultTable[i - 1][j] || resultTable[i][j - 1];
            }
            else if(s3[i + j - 1] == s1[i - 1]){
                resultTable[i][j] = resultTable[i - 1][j];
            }
            else if(s3[i + j - 1] == s2[j - 1]){
                resultTable[i][j] = resultTable[i][j - 1];
            }
        }
    }

    cout << s1.length() << " and " << s2.length() << endl;
    for(int i = 0; i <= s1.length(); i ++){
        for(int j = 0; j <= s2.length(); j++){
            cout << resultTable[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return resultTable[s1.length()][s2.length()];
}

int main(int argc, char const *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";

    isInterleave(s1, s2, s3);
    /*
    bool resultTable[1000][1000];
    resultTable[0][0] = true;
    for(int i = 0; i < s1.length(); i ++){
        resultTable[i][0] = (s1[i] == s3[i]); 
    }
    for(int j = 0; j < s2.length(); j ++){
        resultTable[0][j] = (s2[j] == s3[j]); 
    }

    for(int i = 0; i < s1.length(); i ++){
        for(int j = 0; j < s2.length(); j++){
            cout << resultTable[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*

 */

