#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
 */


bool isIsomorphic(string s, string t) {

}

int main(int argc, char const *argv[])
{
    string a = "ab";
    string b = "aa";
    cout << (isIsomorphic(a, b) ? "true" : "false") << endl;
    return 0;
}
