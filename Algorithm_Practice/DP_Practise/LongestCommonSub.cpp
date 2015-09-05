#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define rownumber 9
#define columnnumber 10
/*
 Given two strings X = x1, x2, ... , xn and Y = y1, y2, ... , ym we want to find the length
  k of the longest string Z = z1, z2, ... , zk where Z appears as a substring of X and as a subsequence
  of Y. Recall, a substring is consecutive elements.
 */
int main(int argc, char const *argv[])
{
    string x = "abdbabfgd";
    string y = "betfdbfafr";

    // string x = "ABAB";
    // string y = "BABA";
    int resultArray[rownumber][columnnumber];
    for(int i = 0; i < rownumber; i ++){
        if(x[i] == y[0])
            resultArray[i][0] = 1;
        else
            resultArray[i][0] = 0;
    }

    for(int i = 0; i < columnnumber; i ++){
        if(x[0] == y[i])
            resultArray[0][i] = 1;
        else
            resultArray[0][i] = 0;
    }

    for(int i = 1; i < rownumber; i ++){
        for(int j = 1; j < columnnumber; j ++){
            if(x[i] == y[j]){
                int maxLastNumber = resultArray[i - 1][0];
                for(int t = 0; t < j; t ++){
                    maxLastNumber = max(maxLastNumber, resultArray[i - 1][t]);
                }
                resultArray[i][j] = maxLastNumber + 1;
            }
            else {
                // resultArray[i][j] = max(resultArray[i][j - 1], resultArray[i - 1][j]);
                resultArray[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < rownumber; i ++){
        for(int j = 0; j < columnnumber; j ++){
            cout << resultArray[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

