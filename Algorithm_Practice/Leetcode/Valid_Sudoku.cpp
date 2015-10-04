#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */


bool isValidSudoku(vector<vector<char> >& board) {
    if(board.empty())
        return false;
    int row = board.size();
    int column = board[0].size();
    
    vector<int>r_v;
    vector<int>c_v;
    vector<int>s_v;

    for(int i = 0; i < 9; i ++){
        r_v.push_back(1);
        c_v.push_back(1);
        s_v.push_back(1);
    }

    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            int number;
            if(board[i][j] != '.'){
                number = board[i][j] - '1';
                if(r_v[number] == 0){
                    cout << "!" << endl;
                    return false;
                }
                if(r_v[number] == 1)
                    r_v[number] = 0;
            }

            if(board[j][i] != '.'){
                number = board[j][i] - '1';
                cout << number << " ";
                if(c_v[number] == 0){
                    cout << "@" << endl;
                    return false;
                }
                if(c_v[number] == 1)
                    c_v[number] = 0;
            }
        }
        
        for(int i = 0; i < 9; i ++){
            r_v[i] = 1;
            c_v[i] = 1;
        }
    }
    
    for(int i = 0; i < 9; i = i + 3){
        for(int j = 0; j < 9; j = j + 3){
            for(int t = i; t < i + 3; t ++){
                for(int k = j; k < j + 3; k ++){
                    if(board[t][k] != '.'){
                        int number = board[t][k] - '1';
                        if(s_v[number] == 0){
                            cout << "ha" << endl;
                            return false;
                        }
                        if(s_v[number] == 1)
                            s_v[number] = 0;
                    }
                }
            }
            for(int i = 0; i < 9; i ++){
                s_v[i] = 1;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<char> > board = {
        {'.','8','7','6','5','4','3','2','1'},
        {'2','.','.','.','.','.','.','.','.'},
        {'3','.','.','.','.','.','.','.','.'},
        {'4','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','.','.'},
        {'6','.','.','.','.','.','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','.','.','.','.','.'},
        {'9','.','.','.','.','.','.','.','.'}
    };

    isValidSudoku(board);
    return 0;
}
/*
位操作还是不熟悉，使用了位操作可以简化很多代码。具体实现如下.
   bool isValidSudoku(vector<vector<char>>& board) {
    vector<short> col(9, 0);
    vector<short> block(9, 0);
    vector<short> row(9, 0);
    for (int i = 0; i < 9; i++)
     for (int j = 0; j < 9; j++) {
         if (board[i][j] != '.') {
             int idx = 1 << (board[i][j] - '0');
             if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                return false;
            row[i] |= idx;
            col[j] |= idx;
            block[i/3 * 3 + j/3] |= idx;
         }
     }
     return true;
  }
 */