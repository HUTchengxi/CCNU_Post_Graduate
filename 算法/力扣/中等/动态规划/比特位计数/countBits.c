#include <stdio.h>
#include <stdlib.h>

int countBitOne(int x) {

    int result = 0;
    while(x != 0) {
        result++;
        x &= (x-1);
    }
    return result;
}

/**
 * 简单粗暴计算形式：x & x-1，每次都会将x的二进制形式的最后一个1变成0
 * @param num
 * @param returnSize
 * @return
 */
int* countBitsOne(int num, int* returnSize) {

    int *results = (int*) malloc(sizeof(int) * (num + 1));
    int idx;
    *returnSize = num + 1;
    for(idx = 0; idx <= num; idx++) {
        results[idx] = countBitOne(idx);
    }
    return results;
}

/**
 * 通过最高有效位实现
 * @param num
 * @param returnSize
 * @return
 */
int* countBitsTwo(int num, int* returnSize) {

    int *results = (int*) malloc(sizeof(int) * (num + 1));
    int idx, highBit = 0;
    *returnSize = num + 1;
    results[0] = 0;

    for(idx = 1; idx <= num; idx++) {
        // == 优先级高于 &
        if((idx & (idx-1)) == 0) {
            highBit = idx;
        }
        results[idx] = results[idx - highBit] + 1;
    }

    return results;
}

/**
 * 通过最低有效位实现
 * @param num
 * @param returnSize
 * @return
 */
int* countBitsThree(int num, int* returnSize) {

    int *results = (int*) malloc(sizeof(int) * (num + 1));
    int idx;
    *returnSize = num + 1;
    results[0] = 0;

    for(idx = 1; idx <= num; idx++) {
        results[idx] = results[idx/2] + (idx&1);
    }

    return results;
}

/**
 * 通过最低设置位实现
 * @param num
 * @param returnSize
 * @return
 */
int* countBitsFour(int num, int* returnSize) {

    int *results = (int*) malloc(sizeof(int) * (num + 1));
    int idx;
    *returnSize = num + 1;
    results[0] = 0;

    for(idx = 1; idx <= num; idx++) {
        results[idx] = results[idx & (idx-1)] + 1;
    }

    return results;
}

int main() {

    int n = 5;
//    printf("input n: ");
//    scanf("%d", &n);

    int m;
    int *results = countBitsFour(n, &m);

    int idx;
    for(idx = 0; idx <= n; idx++) {
        printf("%d\t", results[idx]);
    }

    return 0;
}
