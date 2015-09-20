#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
 */


bool searchRecursion(vector<vector<int>>& matrix, int target,int m, int n, 
                    int row, int column, int m_row, int m_column) {
    if(column == 1 && row == 1)
        return (target == matrix[m][n]);
    int count = 0;
    while(count < row || count < column){
        if(m < m_row && n < m_column) {
            if(matrix[m + count][n + count] == target)
                return true;
            if(matrix[m + count][n + count] > target){
                return (searchRecursion(matrix, target, m, n + count, count, column - count, m_row, m_column) || 
                    searchRecursion(matrix, target, m + count, n, row - count, count, m_row, m_column));
            }
        }
        count ++;
    }

    if(row == count)
        return searchRecursion(matrix, target, m + count, n + count, 1, column - count, m_row, m_column);
    if(column == count)
        return searchRecursion(matrix, target, m + count, n + count, row - count, 1, m_row, m_column);
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > matrix = {{1,2,3,4,5}};
    int target = 5;
    if(matrix.empty() || matrix[0].empty())
        return false;
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    cout << m << " " << n << endl;
    cout << (searchRecursion(matrix, target, 0, 0, m , n, m, n) ? "true" : "false") << endl;

    return 0;
}

/*

 */