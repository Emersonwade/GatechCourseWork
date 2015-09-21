#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*

***********************NOT FINISHED************************
 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

void choose(int start, int end, vector<vector<int> >&result, int max)
{
    for(int i = start; i < max; i ++){
        vector<int> temp;
        temp.push_back(i);

    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    // cout << "PLS input the number n and number k" << endl;
    // cin >> n >> k;

    string a = "2123";
    int i = atoi(a.c_str());
    cout << i << endl;

    string s = to_string(42);

    for(auto i = 0; i < 5; i ++)
        cout << "a" << endl;
    //string c = to_string(i);
    //cout << c << endl;
    // vector<vector<int> >result;

    // for(int i = 0; i < k; i ++){
    //     for(int j = 0; j < n; j ++){

    //     }
    // }


    // for(int i = 0; i < result.size(); i ++){
    //     for(int j = 0; j < result[i].size(); j ++){
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
