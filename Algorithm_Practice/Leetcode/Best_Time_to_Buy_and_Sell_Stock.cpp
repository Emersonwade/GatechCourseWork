#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        vector<int> result(prices.size(), 0);
        int maxP = 0;
        for(int i = 1; i < prices.size(); i++){
            result[i] = max(result[i - 1] + prices[i] - prices[i - 1], 0);
            maxP =max(maxP, result[i]);
        }
        return maxP;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int maxP = 0;
        int minP = prices[0];
        for(int i = 0; i < prices.size(); i ++){
            minP = min(minP, prices[i]);
            maxP = max(maxP, prices[i] - minP);
        }
        return maxP;
    }
};

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题还是有不少解法的，我最开始想到的是Solution1的解法，其实不是最优的。使用了O(n) time and O(n) space.
I store the DP information in the result matrix. i.e. 
1 2 7 4 9 3 2 5 10
I would store
0 1 6 3 8 2 1 4 9 in result matrix and use maxP to compare and get the final answer.

But then I found a better way to solve problem which is solution2.
In solution2, I store the minimun number of the stock price. And use the current prices[i] - minP. In that way, actually
I can get max price for prices[0..1] prices[0...2] prices[0...3]...prices[0...n] which is useful in problem Best Time
to Buy and Sell Stock III.
And also the space is O(1).
 */
}
}
}

