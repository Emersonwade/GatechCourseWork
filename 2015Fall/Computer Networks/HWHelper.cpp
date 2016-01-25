#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*

 */

int main(int argc, char const *argv[])
{
    // float matrix[6][6] = {
    //     {0, 102.969, 14.565, 7.626, 64.974, 77.181}, 
    //     {102.969, 0, 109.961, 70.686, 10.716, 15.995}, 
    //     {14.565, 109.961, 0, 11.511, 64.099, 79.968}, 
    //     {7.626, 70.686, 11.511, 0, 89.094, 72.494}, 
    //     {64.974, 10.716, 64.099, 89.094, 0, 14.030}, 
    //     {77.181, 15.995, 79.968, 72.494, 14.030, 0}, 
    // };

    float matrix[6][6] = {
        {0,   104.363, 10.510,  1.952,   63.486,  75.958},
        {104.363, 0,   109.142, 70.098,  10.231,  15.453},
        {10.510,  109.142, 0,   11.507,  63.895,  80.725},
        {1.952,   70.098,  11.507,  0,   89.097,  74.577},
        {63.486,  10.231,  63.895,  89.097,  0,   78.599},
        {75.958,  15.453,  80.725,  74.577,  78.599,  0},
    };

    
    vector<float> result;
    for(int i = 0; i < 6; i ++){
        for(int j = i; j < 6; j ++){
            if(matrix[i][j] == 0)
                continue;
            
            for(int t = 0; t < 6; t ++){
                if(matrix[i][t] == 0 || matrix[t][j] == 0)
                    continue;
                result.push_back(matrix[i][j] / (matrix[i][t] + matrix[t][j]));
            }
        }
    }

    cout << result.size() << endl;
    for(vector<float>::iterator i = result.begin(); i != result.end(); i ++)
        cout << *i << endl;

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}


