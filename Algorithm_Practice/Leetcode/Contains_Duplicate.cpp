#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value 
appears at least twice in the array, and it should return false if every element is distinct.
 */
bool containsDuplicate(vector<int>& nums) {
    if(nums.empty())
        return false;
    unordered_set<int>s;
    for(int i = 0; i < nums.size(); i ++){
        if(s.find(nums[i]) != s.end())
            return true;
        s.insert(nums[i]);
    }
    return false;
}

bool containsDuplicate(vector<int>& nums) {
    if(nums.empty())
        return false;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 1; i ++){
        if(nums[i] == nums[i + 1])
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
This is an easy problem, the reason I put it here because of the first solution that use the unordered_set.
unordered_set is the way to contain the single element instead of unordered_map.
 */

