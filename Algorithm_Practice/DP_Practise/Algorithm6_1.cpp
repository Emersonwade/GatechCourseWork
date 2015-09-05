#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define ARRAY_NUMBER 12
/*
A contiguous subsequence of a list S is a subsequence made up of consecutive elements of S. For instance, if S is
5, 15, −30, 10, −5, 40, 10,
then 15, −30, 10 is a contiguous subsequence but 5, 15, 40 is not. Give a linear-time algorithm for
the following task:
Input: A list of numbers, a1, a2, . . . , an.
Output: The contiguous subsequence of maximum sum (a subsequence of length zero has sum zero).
For the preceding example, the answer would be 10, −5, 40, 10, with a sum of 55.
 */
 
int main(int argc, char const *argv[])
{
    int sampleArray[ARRAY_NUMBER] = {5, 15, -30, 10, -5, 40, 10, -10, -20, -10, 30, 20};
    int result[ARRAY_NUMBER];

    result[0] = sampleArray[0];
    for(int i = 1; i < ARRAY_NUMBER; i ++){
        result[i] = max(result[i - 1] + sampleArray[i], sampleArray[i]);
    }

    for(int i = 0; i < ARRAY_NUMBER; i ++){
        cout << result[i] << endl;
    }
    return 0;
}

