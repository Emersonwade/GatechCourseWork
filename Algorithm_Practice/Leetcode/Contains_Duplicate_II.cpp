#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in 
the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 */
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.empty())
        return false;
        
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i ++){
        unordered_map<int, int>::iterator it = m.find(nums[i]);
        if(it != m.end()){
            if( i - it->second <= k)
                return true;
            else
                it->second = i;
        }
        m.insert(unordered_map<int,int>::value_type(nums[i], i));
    }
    return false;
}

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这里唯一需要注意的点是在于找到了一个相同的之后，一旦i-it->second > k之后需要更新新的i->second值。
例如1 0 1 1 K = 1的话，不更新的话就不能得到正确答案了
并且这里使用了unordered_map,注意unordered_map的插入方法为插入value_type(,)
 */

