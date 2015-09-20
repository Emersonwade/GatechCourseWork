#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */


int removeDuplicates(vector<int>& nums) {
    map<int, int> m;
    int result = 0;
    for(vector<int>::iterator i = nums.begin(); i != nums.end(); i ++){
        map<int, int>::iterator m_i = m.find(*i);
        if(m_i == m.end()){
            m[*i] = 1;
            result ++;
        }
        else {
            if(m_i->second == 1){
                m[*i] = 2;
                result ++;
            }
            else{
                nums.erase(i);
                i --;
            }
        }
    }
    return result;
}


int main(int argc, char const *argv[])
{

    return 0;
}

/*
int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
    return n - count;
}
 */