#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

void swapVector(vector<vector<int> >& result,vector<int> nums, int swapPosition) {
    for(int i = swapPosition; i < nums.size(); i ++){
        swap(nums[swapPosition], nums[i]);
        if(swapPosition != i)
            result.push_back(nums);
        else{
            if(swapPosition == 0)
                result.push_back(nums);
        }
        swapVector(result, nums, swapPosition + 1);

    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > result;
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    swapVector(result, nums, 0);
    for(int i = 0; i < result.size(); i ++){
        for(int j = 0; j < result[i].size(); j ++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

