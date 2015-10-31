#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
 */

bool isPalindrome (string s, int start, int end){
    while(start < end){
        if(s[start] != s[end])
            return false;
        start ++;
        end --;
    }
    return true;
}

void partitionBT(vector<vector<string> >& result, vector<string>& temp, int currP, string s){
    if(currP >= s.length()){
        result.push_back(temp);
        return;
    }

    for(int i = 1; i <= s.length() - currP; i ++){
        if(isPalindrome(s, currP, currP + i - 1)){
            temp.push_back(s.substr(currP, i));
            partitionBT(result, temp, currP + i, s);
            temp.pop_back();
        }
    }
    
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    vector<string> temp;
    partitionBT(result, temp, 0, s);
    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<string> > result = partition("a");
    for(int i = 0; i < result.size(); i ++){
        for(int j = 0; j < result[i].size(); j ++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    //system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
Standard Backtracking. Remeber how to write backtracking method.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        getPartition(s, 0, tmp, res);
        return res;
    }
private: 
    void getPartition(string& s, int idx, vector<string>& tmp, vector<vector<string>>& res) {
        if (idx == s.length()) {
            res.push_back(tmp);
            return;
        }
        for (int i = idx, n = s.length(); i < n; i++) {
            int l = idx, r = i;
            while (l < r && s[l] == s[r]) l++, r--;
            if (l >= r) {
                tmp.push_back(s.substr(idx, i - idx + 1));
                getPartition(s, i + 1, tmp, res);
                tmp.pop_back();
            }
        }
    }
};
 */

