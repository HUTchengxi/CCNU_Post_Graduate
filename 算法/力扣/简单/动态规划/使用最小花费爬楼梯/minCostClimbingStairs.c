#include<stdio.h>

/**
 * 使用最小花费爬阶梯
 * https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * @param cost
 * @param costSize
 * @return
 */
int minCostClimbingStairs(int* cost, int costSize){

    int dp[costSize+1];

    // init
    dp[0] = 0;
    dp[1] = 0;

    // status trans formula
    int idx;
    for(idx = 2; idx <= costSize; idx++) {
        dp[idx] = dp[idx-1] + cost[idx-1] < dp[idx - 2] + cost[idx - 2] ?
                  dp[idx - 1] + cost[idx - 1] : dp[idx - 2] + cost[idx - 2];
    }

    return dp[costSize];

}

int main() {

    int costs[] = {10, 15, 20};
    int costSize = 3;

    printf("the result is %d\n", minCostClimbingStairs(costs, costSize));
    return 0;
}