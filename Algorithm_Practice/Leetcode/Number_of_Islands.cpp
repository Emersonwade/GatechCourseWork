#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
注意vector的边界，如果需要通过vector[i][j] i j 千万是vector.size() - 1
这种题目可以多考虑DFS，DFS能解决相当多问题
 */
void dfsIsland(int row, int column, vector<vector<char> >& grid){
    if(grid[row][column] == '0'){
        cout << "!!!" << endl;
        return;
    }
    else {
        grid[row][column] = '0';
        int max_row = grid.size() - 1;
        int max_column = grid[0].size() - 1;
        
        dfsIsland(min(row + 1, max_row), column, grid);
        dfsIsland(row, min(column + 1, max_column), grid);
        dfsIsland(max(0, row - 1), column, grid);
        dfsIsland(row, max(0, column - 1), grid);
    }
}

int numIslands(vector<vector<char> >& grid) {
    if(grid.empty())
        return 0;
    int row = grid.size();
    int column = grid[0].size();
    int result = 0;

    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j ++){
            if(grid[i][j] == '1'){
                result ++;
                dfsIsland(i, j, grid);
            }
        }
    }
    
    return result;
}

int main(int argc, char const *argv[])
{    
    vector<vector<char> > grid;
    vector<char>a;
    a.push_back('1');    a.push_back('1');    a.push_back('1');
    vector<char>b;
    b.push_back('0');    b.push_back('1');    b.push_back('0');
    vector<char>c;
    c.push_back('1');    c.push_back('1');    c.push_back('1');
    grid.push_back(a);grid.push_back(b);grid.push_back(c);

    cout << numIslands(grid) << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*

 */

