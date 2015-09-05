#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Given two strings x = x1x2 ···xn and y = y1y2 ···ym, we 
wish to find the length of their longest commonsubstring,
that is,the large stk for which there are indices i and j with 
xi xi+1···xi+k−1 = yj yj+1 · · · yj+k−1 . Show how to do this in time O(mn).
 */

int main(int argc, char const *argv[])
{
    string inputStringX = "abcdefghijklmn";
    string inputStringY = "abcegabcdijkamn";

    int ** resultArray;
    int result = 0;

    resultArray = new int *[inputStringX.length()];
    for(int i = 0; i < inputStringX.length(); i ++){
        resultArray[i] = new int [inputStringY.length()];
    }

    for(int i = 0; i < inputStringX.length(); i ++){
        if (inputStringX[i] == inputStringY[0]){
            resultArray[i][0] = 1;
            result = 1;
        }
        else
            resultArray[i][0] = 0;
    }

    for(int j = 0; j < inputStringY.length(); j ++){
        if (inputStringY[j] == inputStringX[0]){
            resultArray[0][j] = 1;
            result = 1;
        }
        else
            resultArray[0][j] = 0;
    }

    for(int i = 1; i < inputStringX.length(); i ++){
        for(int j = 1; j < inputStringY.length(); j ++){
            if(inputStringX[i] == inputStringY[j]) {
                resultArray[i][j] = resultArray[i - 1][j - 1] + 1;
                result = max(result, resultArray[i][j]);
            }
            else 
                resultArray[i][j] = 0;
        }
    }

    cout << "result is " << result << endl;

    for(int i = 0; i < inputStringX.length(); i ++){
        delete[] resultArray[i];
    }
    delete[] resultArray;
    return 0;
}

