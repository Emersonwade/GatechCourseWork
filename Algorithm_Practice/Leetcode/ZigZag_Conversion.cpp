#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define ARRAY_NUMBER 12
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

int main(int argc, char const *argv[])
{
    string source;
    int n;
    string result;

    cout << "PLS input the number of rows" << endl;
    cin >> n;
    cout << "PLS input the string" << endl;
    cin >> source;

    int columns = (source.length() / (n + n - 2) + 1) * (n - 1);

    char ** matrix = new char *[n];
    for(int i = 0; i < n; i ++){
        matrix[i] = new char[columns];
        for(int j = 0; j < columns; j ++){
            matrix[i][j] = '1';
        }
    }

    int row = 0, column = 0;
    for(int i = 0; i < source.length(); i ++){
        matrix[row][column] = source[i];
        if(row < n - 1){
            row ++;
        }
        else {
            column ++;
            row = 0;
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < column; j ++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

