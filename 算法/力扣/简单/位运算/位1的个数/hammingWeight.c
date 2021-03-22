#include<stdio.h>
#include <stdint.h>

/**
 * 位运算优化：n & n-1 每次都会将最后一位二进制数转换成0
 * @param n
 * @return
 */
int hammingWeight(uint32_t n) {

    int result = 0;
    while (n) {
        n &= n - 1;
        result++;
    }
    return result;
}

/**
 * 简单的循环每位判断
 * @param n
 * @return
 */
int hammingWeightOne(uint32_t n) {

    int i, result = 0;
    long long temp = 1;
    for (i = 0; i < 32; i++) {
        temp *= (i == 0 ? 1 : 2);
        if (n & temp) {
            result++;
        }
    }
    return result;
}