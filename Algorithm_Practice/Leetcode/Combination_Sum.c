#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
 */

void tracking(vector<int>& v, vector<int>& candidates, int start, int target, int maxSize, vector<vector<int>>& result) {
    if(target == 0){
        result.push_back(v);
        return;
    }
    else if(target < 0){
        return;
    }
    
    for(int i = start; i <= maxSize; i ++){
        v.push_back(candidates[i]);
        tracking(v, candidates, i , target - candidates[i], maxSize, result);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> v;
    int maxSize = candidates.size() - 1;
    sort(candidates.begin(), candidates.end());
    tracking(v, candidates, 0, target, maxSize, result);
    return result;
}

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题还是一道回溯算法，具体解释参照Combination题目。
 */

