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

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

