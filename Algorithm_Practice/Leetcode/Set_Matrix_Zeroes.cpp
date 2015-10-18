#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */

void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.empty())
        return;
    int max_r = matrix.size();
    int max_c = matrix[0].size();
    
    bool f_rIsZero = false, f_cIsZero = false;
    
    for(int i = 0; i < max_r; i ++){
        if(matrix[i][0] == 0){
            f_cIsZero = true;
            break;
        }
    }
    for(int i = 0; i < max_c; i ++){
        if(matrix[0][i] == 0){
            f_rIsZero = true;
            break;
        }
    }
    
    for(int row = 1; row < max_r; row ++){
        for(int column = 1; column < max_c; column ++){
            if(matrix[row][column] == 0){
                matrix[row][0] = 0;
                matrix[0][column] = 0;
            }
        }
    }
    
    for(int row = 1; row < max_r; row ++){
        if(matrix[row][0] == 0)
            for(int column = 1; column < max_c; column ++)
                matrix[row][column] = 0;
    }
    
    for(int column = 1; column < max_c; column ++){
        if(matrix[0][column] == 0)
            for(int row = 1; row < max_r; row ++)
                matrix[row][column] = 0;
    }
    
    if(f_rIsZero)
        for(int column = 0; column < max_c; column ++)
            matrix[0][column] = 0;
    if(f_cIsZero)
        for(int row = 0; row < max_r; row ++)
            matrix[row][0] = 0;
}

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题的难度并不高，主要点在如何使用尽量少额外的空间，而我们需要注意到每一个0存在都是对应于一行和一列的，
也就是说我们可以使用第0行和第0列代表第n列是否是0，第n行是否是0.
0 0 1 1 1
1
1
1
0
也就代表了第1列全是0，第4行全是0，这里需要额外注意的就是对于第0行和第0列的处理，因为我们需要对其进行覆盖，
所以优先遍历一遍0行，0列，使用两个bool变量进行表示第0行，第0列是否为0即可。
 */

