#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*

 */

int main(int argc, char const *argv[])
{   
    string s = "s    ";
    vector<string> result;
    string resultStr = "";
    string oneStr = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            oneStr += s[i];
        } else {
            if (oneStr != "") {
                result.push_back(oneStr);
            }            
            oneStr = "";
        }
    }
    if (oneStr != "") {
        result.push_back(oneStr);
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        //cout << result[i] << endl;
        resultStr += result[i];
        if (i != 0) {
            resultStr += " ";
        }
    }

    //cout << resultStr << endl;
    s = resultStr;
    cout << s << endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*

 */

