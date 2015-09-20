#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
 */

void rotateRecursion(int n, vector<vector<int>>& matrix, int size){
    if( size < 1)
        return;

    cout <<"n is " << n << " size is " << size << endl;
    vector<int>oN1;
    vector<int>oN2;
    vector<int>oN3;
    vector<int>oN4;
    
    for(int i = 0; i <= size; i ++){
        oN1.push_back(matrix[n][n + i]);
        oN2.push_back(matrix[n + i][n + size]);
        oN3.push_back(matrix[n + size][n + size - i]);
        oN4.push_back(matrix[n + size - i][n]);
    }
    
    for(int i = 0; i <= size; i ++){
        matrix[n + i][n + size] = oN1[i];
        matrix[n + size][n + size - i] = oN2[i];
        matrix[n + size - i][n] = oN3[i];
        matrix[n][n + i] = oN4[i];
    }

    rotateRecursion(n + 1, matrix, size - 2);
}

void rotate(vector<vector<int>>& matrix) {
    rotateRecursion(0, matrix, matrix.size() - 1);
}
int main(int argc, char const *argv[])
{   
    vector<vector<int> > matrix = {{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},{33,1,20,7,21,7},{4,24,1,6,32,34}};

    rotate(matrix);
    for(int i = 0; i < matrix.size(); i ++){
        for(int j = 0; j < matrix.size(); j ++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl;
    }

    return 0;
}
/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix.size()/2;
        int b = matrix.size();
        for (int i = 0; i< num; i++){
            for (int j = i; j<(b-i-1); j++){
                swap(matrix[i][j], matrix[j][b-i-1]);
                swap(matrix[i][j], matrix[b-i-1][b-j-1]);
                swap(matrix[i][j], matrix[b-j-1][i]);
            }
        }
    }
};

http://fisherlei.blogspot.com/2013/01/leetcode-rotate-image.html
*/