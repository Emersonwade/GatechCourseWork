#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 */

int search(int start, int end, int target, vector<int> nums)
{
    if(start == end){
        if (target <= nums[start])
            return start;
        else
            return start + 1;
    }

    int mid = (start + end) / 2;
    if(target > nums[mid]){
        return search(mid + 1, end, target, nums);
    }
    else if(target < nums[mid]){
        return search(start, mid, target, nums);
    }
    else{
        return mid;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int target;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);

    cout << "PLS Input the target" << endl;
    cin >> target;

    int end = nums.size();
    cout << search(0, end - 1, target, nums) << endl;

    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

