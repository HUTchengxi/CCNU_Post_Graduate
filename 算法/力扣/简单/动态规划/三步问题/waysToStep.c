#include<stdio.h>

/**
 * 三步问题
 * https://leetcode-cn.com/problems/three-steps-problem-lcci/submissions/
 * @param n
 * @return
 */
int waysToStep(int n){

    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }

    // int类型会溢出
    long dp[n+1];

    // init
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    int idx;
    for(idx = 3; idx <= n; idx++) {
        dp[idx] = (dp[idx-1] + dp[idx - 2] + dp[idx - 3]) % 1000000007;
    }

    return dp[n];
}

int main() {

    printf("input n: ");
    int n;
    scanf("%d", &n);

    printf("result is %d\n", waysToStep(n));

    return 0;
}
