#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int maxRow = matrix.size() - 1;
        int maxColumn = matrix[0].size() - 1;
        
        int lowR = 0;
        int highR = maxRow;
        int midRow = 0;
        while(lowR <= highR){
            midRow = (lowR + highR) / 2;
            if(matrix[midRow][0] < target)
                lowR = midRow + 1;
            else if(matrix[midRow][0] > target)
                highR = midRow - 1;
            else
                return true;
        }
        
        if(matrix[midRow][0] > target)
            midRow --;
        if(midRow < 0)
            return false;
            
        int lowC = 0;
        int highC = maxColumn;
        while(lowC <= highC){
            int mid = (lowC + highC) / 2;
            if(matrix[midRow][mid] < target)
                lowC = mid + 1;
            else if(matrix[midRow][mid] > target)
                highC = mid - 1;
            else
                return true;
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
这一题就是典型的二分查找，而我发现我对于二分查找的写法竟然不熟练，这个需要牢记。
具体如下：
        int lowC = 0;
        int highC = maxColumn;
        while(lowC <= highC){
            int mid = (lowC + highC) / 2;
            if(matrix[midRow][mid] < target)
                lowC = mid + 1;
            else if(matrix[midRow][mid] > target)
                highC = mid - 1;
            else
                return true;
        }
 */

