#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
You are given a checkerboard with n rows and n columns, try to find a largest way to from 0 0 to n n.
 */
int main(int argc, char const *argv[])
{
    int sampleArray[3][3] = {
        3, 30, 12, -12, 7, -9, 39, -2, 15
    };

    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++){
            cout << sampleArray[i][j] << " ";
        }
        cout << endl;
    }

    int resultArray[3][3];
    resultArray[0][0] = sampleArray[0][0];

    for(int i = 1; i < 3; i ++){
        resultArray[0][i] = resultArray[0][i - 1] + sampleArray[0][i];
        resultArray[i][0] = resultArray[i - 1][0] + sampleArray[i][0];
    }

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            if (i >= 1 && j >= 1) {
                int tempresult0 = resultArray[i - 1][j - 1] + sampleArray[i][j];
                int tempresult1 = resultArray[i - 1][j] + sampleArray[i][j];
                int tempresult2 = resultArray[i][j - 1] + sampleArray[i][j];
                
                resultArray[i][j] = max(max(tempresult0, tempresult1), tempresult2);
            }
        }
    }

    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++){
            cout << resultArray[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

