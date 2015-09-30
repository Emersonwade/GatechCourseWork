#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define ARRAY_NUMBER 12
/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
 */

string longestPalindrome(string s) {
    int start_p = 0;
    int max_len = 0;
    bool result_table[1000][1000] = {false};
    for(int i = 0; i < s.size(); i ++){
        result_table[i][i] = true;
        if(max_len < 1){
            max_len = 1;
            start_p = i;
        }
        
        if(s[i] == s[i + 1]){
            result_table[i][i + 1] = true;
            start_p = i;
            max_len = 2;
        }
    }
    for(int len = 3; len <= s.size(); len ++){
        for(int i = 0; i < s.size() - len + 1; i ++){
            int j = i + len - 1;
            if((s[i] == s[j]) && result_table[i + 1][j - 1]){
                result_table[i][j] = true;
                if(len >= max_len){
                    max_len = len;
                    start_p = i;
                }
            }
        }
    }
    
    return s.substr(start_p, max_len);
}

int main(int argc, char const *argv[])
{

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

