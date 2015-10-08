#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 */
enum Mtype{
    UP,
    DOWN
};

int candy(vector<int>& ratings) {
    if(ratings.empty())
        return 0;
    int sum = 1;
    int maxC = 0;
    int minC = 0;
    Mtype mt;
    
    for(int i = 1; i < ratings.size(); i ++){
        if(ratings[i] > ratings[i - 1]){
            if(mt != UP)
                minC = i - 1;
            mt = UP;
            sum = sum + i - minC + 1;
        }
        else if(ratings[i] < ratings[i - 1]){
            if(mt != DOWN)
                maxC = i - 1;
            mt = DOWN;
            if(i - maxC <= maxC - minC)
                sum = sum + i - maxC;
            else
                sum = sum + i - maxC + 1;
        }
        else{
            maxC = i;
            minC = i;
            sum ++;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这里我使用了MaxC 和MinC用来记录整个给糖果的趋势，X
                                          X  X 
                                            X  X
                                                X
                                                 X
这样的话就会有最高点和最低点，而只需要在最低点给1个糖果，比他高的给+1就好，注意，所有最低点都给1，上图中有两个最低点。
需要额外注意的是rating相同的情况，rating相同的情况下，我们需要刷新最低点。
X X
   X
    X
     X X X
        X
需要额外注意的情况是，X
                   X   X
                    X X X
                     X   X
                          X
                           X
中，下降的层数过于多，所以加的糖果也需要变得更多，
            if(i - maxC <= maxC - minC)
                sum = sum + i - maxC;
            else
                sum = sum + i - maxC + 1;
所以针对于一个max顶点两端的高度需要进行判断。
 */

