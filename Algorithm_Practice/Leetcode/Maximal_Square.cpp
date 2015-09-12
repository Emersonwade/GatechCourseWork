#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4
 */

int maximalSquare(int i, int j, vector< vector<char> > &matrix)
{
    int lastLength = maximalSquare(i - 1, j - 1);
    bool rowCheck = true, columnCheck = true;
    for(int t = i - lastLength; t < i; t ++){
        if (matrix[t][j] == 0){
            rowCheck = false;
            break;
        }
    }
    for(int t = j - lastLength; t < j; t ++){
        if (matrix[i][t] == 0){
            columnCheck = false;
            break;
        }
    }
    if(rowCheck && columnCheck\ && (matrix[i][j] == 1)){
        return lastLength + 1;
    }
}

int main(int argc, char const *argv[])
{
    vector< vector<char> > matrix;
    
    printf("1212121\n");
    return 0;
}

