#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)  -3  3
-5  -10 1
10  30  -5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
 */

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        if(dungeon.empty())
            return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        int minHP;
        if(dungeon[m - 1][n - 1] < 0)
            minHP = 1 - dungeon[m - 1][n - 1];
        else
            minHP = 1;
        vector<vector<int>> health(m, vector<int>(n, minHP));
        
        for(int i = m -2; i >= 0; i -- ){
            health[i][n - 1] = max(1, health[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        
        for(int i = n -2; i >= 0; i -- ){
            health[m - 1][i] = max(1, health[m - 1][i + 1] - dungeon[m - 1][i]);
        }
        
        for(int i = m - 2; i >= 0; i --){
            for(int j = n - 2; j >= 0; j --){
                health[i][j] = min(max(1, health[i + 1][j] - dungeon[i][j]), max(1, health[i][j + 1] - dungeon[i][j]));
            }
        }
        
        return health[0][0];
    }
};

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题也是使用DP来完成，但是这一题的DP和之前的similar problem中的DP不一样的点，是我们需要从右下方开始DP的循环，
这一题每一个Table(i,j)表示从这个点到最后的点所需要的HP的值，所以我们从右下方开始循环，循环至左上角，那么我们就
得到了最后的答案。
和Minimum Path Sum，unique path都是相同的想法，只不过前几题都是正常的从左上角进行顺序突破，这一题从最后开始。
 */

