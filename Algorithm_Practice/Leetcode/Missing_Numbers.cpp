#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

int missingNumber(vector<int>& nums) {
    int sum = (0 + nums.size()) * (nums.size() + 1) / 2;
    for(int i = 0; i < nums.size(); i ++){
        sum = sum - nums[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{   
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
class Solution {
public:
int missingNumber(vector<int>& nums) {
    //return solution1(nums);
    //return solution2(nums);
    return solution3(nums);
}
private:
int solution1(vector<int>& nums) {
    int sz = nums.size(), i;
    bool *a = new bool[sz];
    memset(a, 1, sz);
    for(i = 0; i < sz; i++){
        if(nums[i] < sz) a[nums[i]] = 0;
    }
    for(i = 0; i < sz; i++)
        if(a[i]) break;
    delete a;
    return i;
}
int solution2(vector<int>& nums){
    int sz = nums.size(), sum = 0;
    for(int i = 0; i < sz; i++)
        sum += nums[i];
    return sz * (sz + 1) / 2 - sum;
}
int solution3(vector<int>& nums){
    int sz = nums.size(), result = sz;
    for(int i = 0; i < sz; i++){
        result ^= i;
        result ^= nums[i];
    }
    return result;
}
};
 */