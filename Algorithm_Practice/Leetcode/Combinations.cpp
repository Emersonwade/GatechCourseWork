#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/* 
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

void combination(vector<int>& v, int start, int n, int k, vector<vector<int>>& result){
    if(k == 0){
        result.push_back(v);
        return;
    }
    
    for(int i = start; i <= n; i ++){
        v.push_back(i);
        combination(v, i + 1, n, k - 1, result);
        v.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> v;
    combination(v, 1, n, k, result);
    return result;
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
/*
这是一个标准的回溯算法的应用，这种题类型还有八皇后等。具体的Combination Sum I II III也都是使用回溯法。
回溯法的精髓就在于

if(k == 0){
    result.push_back(v);
    return;
}

for(int i = start; i <= n; i ++){
    v.push_back(i);
    combination(v, i + 1, n, k - 1, result);
    v.pop_back();
}

k == 0这样的是一个回溯法结束的条件，而关键则在于下面的循环，加入一个新的值(push_back(i))之后，对剩下的值进行尝试，
而尝试完了则pop_back(i)对下一个i进行尝试。

 */