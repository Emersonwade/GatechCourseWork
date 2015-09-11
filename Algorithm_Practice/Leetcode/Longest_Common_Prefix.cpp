#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.
 */

int main(int argc, char const *argv[])
{
    vector<string> strs;
    strs.push_back("aab");
    strs.push_back("aaaaa");
    strs.push_back("abb");
    strs.push_back("aa");

    string result = "";
    for(int j = 0;;j ++){
        bool equal = true;
        char c = strs[0][j];
        for(vector<string>::iterator i = strs.begin(); i != strs.end(); i ++){
            if((*i)[j] != c){
                equal = false;
                break;
            }
        }
        if(equal == false){
            break;
        }
        result = result + c;
    }
    cout << result << endl;

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
