#include<stdio.h>
#include<string.h>

/**
 * 数学归纳法
 * 详细参见：https://leetcode-cn.com/problems/clumsy-factorial/solution/ben-jie-cheng-by-leetcode-solution-deh2/
 * @param N
 * @return
 */
int clumsy(int N) {
    if (N == 1) {
        return 1;
    } else if (N == 2) {
        return 2;
    } else if (N == 3) {
        return 6;
    } else if (N == 4) {
        return 7;
    }

    if (N % 4 == 0) {
        return N + 1;
    } else if (N % 4 <= 2) {
        return N + 2;
    } else {
        return N - 1;
    }
}

/**
 * 按照减号进行划分
 * @param N
 * @return
 */
int clumsy(int N) {

    int count = 0;
    int len = N / 4 + (N % 4 == 0 ? 0 : 1);
    int results[len];
    int idx = -1;
    memset(results, 1, len);
    for (int i = N; i >= 1; i--, count++) {
        int temp = count % 4;
        if (temp == 0) {
            results[++idx] = i;
            continue;
        }
        results[idx] = temp == 1 ? results[idx] * i :
                                    temp == 2 ? results[idx] / i :
                                        idx == 0 ? results[idx] + i :results[idx] - i;
    }

    for (int i = 1; i < len; i++) {
        results[0] -= results[i];
    }
    return results[0];
}

int main() {

    printf("result is %d", clumsy(10));
    return 0;
}