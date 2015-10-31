#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
 */

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

class Solution1 {
public:
    int maxProfitHelper(vector<int>& prices, int start, int end) {
        vector<int> result(end - start + 1, 0);
        int maxP = 0;
        for(int i = 1; i < end - start + 1; i++){
            result[i] = max(result[i - 1] + prices[start + i] - prices[start + i - 1], 0);
            maxP =max(maxP, result[i]);
        }
        return maxP;
    }
    
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int maxP = maxProfitHelper(prices, 0, prices.size() - 1);
        
        for(int i = 0; i < prices.size() - 1; i ++){
            maxP = max(maxProfitHelper(prices, 0, i) +
                maxProfitHelper(prices, i + 1, prices.size() - 1), maxP);
        }
        return maxP;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
            
        vector<int> maxV1(prices.size(), 0);
        vector<int> maxV2(prices.size(), 0);

        int maxP = 0;
        int minP = prices[0];
        for(int i = 0; i < prices.size(); i ++){
            minP = min(minP, prices[i]);
            maxP = max(maxP, prices[i] - minP);
            maxV1[i] = maxP;
        }
        
        maxP = 0;
        int maxS = prices[prices.size() - 1];
        for(int i = prices.size() - 1; i >= 0; i --){
            maxS = max(maxS, prices[i]);
            maxP = max(maxP, maxS - prices[i]);
            maxV2[i] = maxP;
        }
        
        
        maxP = 0;
        for(int i = 0; i < prices.size() - 1; i ++){
            maxP = max(maxV1[i] + maxV2[i], maxP);
        }
        return maxP;
    }
};


public class Solution3 {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
};

/*

 */
