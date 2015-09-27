#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*

 */
void checkNums(vector<vector<char> >& grid, int row, int column) {
    if(grid[row][column] == '0')
        return;
    else{
        if(row >= 1 && column >= 1){
            char r = min(grid[row - 1][column], grid[row][column - 1]);
            if(r == 0)
                grid[row][column] = grid[row][column] + 1 - '0';
            else
                grid[row][column] = r;
        }
        else if(row >= 1){
            char r = grid[row - 1][column];
            if(r == 0)
                grid[row][column] = grid[row][column] + 1 - '0';
            else
                grid[row][column] = r + '0';
        }
        else if(column >= 1){
            char r = grid[row][column - 1];
            if(r == 0)
                grid[row][column] = grid[row][column] + 1 - '0';
            else
                grid[row][column] = r;
        }
    }
}

int numIslands(vector<vector<char> >& grid) {
    if(grid.empty())
        return 0;
    int row = grid.size();
    int column = grid[0].size();
    char result = '0';

    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j ++){
            checkNums(grid, i, j);
        }
    }
    
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j ++){
            result = max(result, grid[i][j]);
        }
    }
    return result - '0';
}

int main(int argc, char const *argv[])
{    
    int a = 1;
    char c = a + '0';
    cout << c << endl;
    //cout << 1 + 1 << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*

 */

