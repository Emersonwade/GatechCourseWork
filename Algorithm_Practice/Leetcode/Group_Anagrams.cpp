#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
 */

class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int currV = 0;
        int primes[] = {3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97, 101, 107};
        unordered_map<int, int> strmap;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i ++){
            int hash_value = 1;
            for(int j = 0; j < strs[i].size(); j ++)
                hash_value *= primes[strs[i][j] - 'a'];

            unordered_map<int, int>::const_iterator it = strmap.find (hash_value);
            if(it != strmap.end()){
                result[it->second].push_back(strs[i]);
            }
            else{
                strmap[hash_value] = currV;
                vector<string> temp (1, strs[i]);
                result.push_back(temp);
                currV ++;
            }
        }
        
        for(int i = 0; i < result.size(); i ++){
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{   
    //system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
In solution1:
Because it only has 26 characters, so I use 26 primes for every character.
And use the multipling the primes as a hash_value.
For example, abc = bac = 2 * 3 *5.

In solution2:
We can make a copy of the original string and then sort that string, and use that 
sting as our hash_value.
 */