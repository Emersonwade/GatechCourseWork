#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 */
/*
在Vecot尚未初始化直接不能直接以result[i][j]形式访问，所以出错。。太坑了
result[i].push_back(min(result[i - 1][j], result[i][j - 1]) + grid[i][j]);
之前写成了
result[i][j](min(result[i - 1][j], result[i][j - 1]) + grid[i][j]);
直接崩了
但是一个vector在初始化时应该会分配少许空间，所以在会在row和column分别小于7时运行良好
 */
int minPathSum(vector<vector<int> >& grid) {
    if(grid.empty() || grid[0].empty())
        return 0;
    int row = grid.size();
    int column = grid[0].size();
    
    vector<vector<int> > result;
    for(int i = 0; i < row; i ++){
        vector<int> temp;
        result.push_back(temp);
    }
    result[0].push_back(grid[0][0]);
    for(int i = 1; i < row; i ++){
        result[i].push_back(result[i - 1][0] + grid[i][0]);
    }
    for(int i = 1; i < column; i ++){
        result[0].push_back(result[0][i - 1] + grid[0][i]);
    }
    
    for(int i = 1; i < row; i ++){
        for(int j = 1; j < column; j ++){
            result[i].push_back(min(result[i - 1][j], result[i][j - 1]) + grid[i][j]);
        }
    }
    
    return result[row - 1][column - 1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > grid;

    static const int arr[] = {1,4,8,6,2,2,1,7};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));
    grid.push_back(vec);
    static const int arr2[] = {4,7,3,1,4,5,5,1};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    grid.push_back(vec2);
    static const int arr3[] = {8,8,2,1,1,8,0,1};
    vector<int> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
    grid.push_back(vec3);
    static const int arr4[] = {8,9,2,9,8,0,8,9};
    vector<int> vec4 (arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]) );
    grid.push_back(vec4);
    static const int arr5[] = {5,7,5,7,1,8,5,5};
    vector<int> vec5 (arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]) );
    grid.push_back(vec5);
    static const int arr6[] = {7,0,9,4,5,6,5,6};
    vector<int> vec6 (arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]) );
    grid.push_back(vec6);
    static const int arr7[] = {4,9,9,7,9,1,9,0};
    vector<int> vec7 (arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]) );
    grid.push_back(vec7);

    minPathSum(grid);
    //cout << minPathSum(grid) << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
在这里还需要再提一下新的DP的解法，也就是说不使用一个二维数组，而是一个一维数组进行储存。节省空间。
想法如下：
0 0 0
0 0 0
0 0 0
每一个代表了到达(i,j)的值
之前都是这样存储的，现在
0 0 0
每一位代表了到达(max_row, j)的值
每一个都代表了到达最后一行的那一列所需要的值，然后在循环中还是每一行每一列的去循环。具体代码如下：

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> pathLength(n, grid[0][0]);
        for(int i = 1; i < n; i ++){
            pathLength[i] = pathLength[i - 1] + grid[0][i];
        }
        
        for(int i = 1; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(j == 0)
                    pathLength[j] = pathLength[j] + grid[i][j];
                else
                    pathLength[j] = min(pathLength[j], pathLength[j - 1]) + grid[i][j];
            }
        }
        
        return pathLength[n - 1];
    }
};
 */