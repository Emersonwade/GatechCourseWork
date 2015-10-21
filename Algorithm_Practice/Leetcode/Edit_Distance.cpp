#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*

 */
void test(string word1){
    //printf("%s\n", word1);
    word1.replace(word1.begin(), word1.begin(), 1,'a');
    cout << word1 << endl;
}


int main(int argc, char const *argv[])
{
    string word1 = "Hello";
    test(word1);
    cout << word1 << endl;
    //system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*

 */

