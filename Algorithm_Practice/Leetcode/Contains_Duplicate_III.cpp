#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given an array of integers, find out whether there are two distinct indices i and j in the 
array such that the difference between nums[i] and nums[j] is at most t and the 
difference between i and j is at most k.
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty())
            return false;
        
        set<int> s;
        int size = nums.size();
        
        for(int i = 0; i < size; i ++){
            set<int>::iterator it = s.upper_bound(nums[i] - t - 1);
            if(it != s.end())
                if(abs(nums[i] - *it) <= t )
                    return true;

            s.insert(nums[i]);
            if(s.size() > k)
                if(i >= k)
                    s.erase(nums[i - k]);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题有相当多的陷阱，以至于我交了无穷次，首先他需要考虑的nums[i] nums[j]相差至多t，
i j相差至多k。
对于nums[i]来说，那我们使用set的upper_bound列出大于等于nums[j] - t的数（注意upper_bound只能列出大于
不能包含等于），再次要检测set里面的数是不是大于了nums[j] + t（此处有第二个陷阱，如果nums[j]和t相当大，
那么就会溢出，所以我们要使用的是abs（set - nums[j] <= t进行比较。）
再次我们要注意的是如果，s.size() > k了就说明我们i 和j的大小超出了k，就要进行删除，删除的话可以使用
erase(nums[i - k])，因为set可以针对于内容删除

 */

