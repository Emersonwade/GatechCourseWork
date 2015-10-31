#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

Subscribe to see which companies asked this question
 */

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i --){
            for(int j = i; j < n; j ++){
                if(s[i] == s[j] && (i + 1 > j - 1 || isPal[i + 1][j - 1] ))
                    isPal[i][j] = true;
            }
        }

        vector<int> cut(n, INT_MAX);
        cut[0] = 0;
        for(int i = 1; i < n; i ++){
            for(int j = i; j >= 0; j --){
                if(isPal[j][i]){
                    if(j == 0)
                        cut[i] = 0;
                    else
                        cut[i] = min(cut[i], cut[j - 1] + 1);
                }
            }
        }
            
        return cut[n - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
Very nice and hard DP problems.
In order to 
 */

