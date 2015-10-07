#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 */

bool jump(vector<int>& nums, int curr) {
    if(curr + nums[curr] >= nums.size() - 1)
        return true;
    if(curr + nums[curr] == curr)
        return false;
    
    int max = 0, counter = 0;
    for(int i = 1; i <= nums[curr]; i ++){
        if(i + nums[curr + i] > max){
            max = i + nums[curr + i];
            counter = i;
        }
    }
    return jump(nums, curr + counter);
}

bool canJump(vector<int>& nums) {
    if(nums.empty())
        return true;
    
    return jump(nums, 0);
}

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题我的思路就是从当前节点找到最远可以到达的地方，然后从接下来的最远可以到达的节点继续找。
例如[2,5,1,2,4,0,1,2,0]
中，第一步，2可以到5和1，明显5可以到的地方更远，从5继续找，5当中可以到的4是接下来最远的，再从4找，
直到超过了最后一个点的位置就可以了。
 */

