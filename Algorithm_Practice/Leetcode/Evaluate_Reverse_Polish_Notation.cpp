#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

int main(int argc, char const *argv[])
{   
    return 0;
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>notation;
        for(vector<string>::iterator i = tokens.begin(); i != tokens.end(); i ++){
            if((*i) == "+"){
                string b = notation.top();
                notation.pop();
                string a = notation.top();
                notation.pop();
                int result = stoi(a) + stoi(b);
                notation.push(to_string(result));
            }
            else if((*i) == "-"){
                string b = notation.top();
                notation.pop();
                string a = notation.top();
                notation.pop();
                int result = stoi(a) - stoi(b);
                notation.push(to_string(result));
            }
            else if((*i) == "*"){
                string b = notation.top();
                notation.pop();
                string a = notation.top();
                notation.pop();
                int result = stoi(a) * stoi(b);
                notation.push(to_string(result));
            }
            else if((*i) == "/"){
                string b = notation.top();
                notation.pop();
                string a = notation.top();
                notation.pop();
                int result = stoi(a) / stoi(b);
                notation.push(to_string(result));
            }
            else{
                notation.push(*i);
            }
        }
        string result = notation.top();
        return stoi(result);
    }
};