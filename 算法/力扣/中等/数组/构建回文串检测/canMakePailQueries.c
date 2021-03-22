#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>

/**
 * 子串
 * @param src
 * @param desc
 * @param start
 * @param end
 */
void subStr(char* src, char* desc, int start, int end) {

    int i=0;
    for(; start <= end; start++) {
        desc[i++] = src[start];
    }
}

/**
 * 回文检测
 * @param str
 * @param allowChange
 * @return
 */
bool huiwenCheck(char *str, int len, int allowChange) {

    int i;
    for(i = 0; i < len/2; i++) {
        if(str[i] != str[len - i - 1] && --allowChange < 0) {
            return false;
        }
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* canMakePaliQueries(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize){

    int len = returnSize[0];
    bool* bools = malloc(sizeof(bool) * len);

    int i;
    for(i = 0; i < queriesSize; i++) {

        int left = queries[i][0];
        int right = queries[i][1];
        int k = queries[i][2];
        int tempLen = right - left + 1;

        // 截取
        char* subS = malloc(sizeof(char) * tempLen);
        subStr(s, subS, left, right);

        // 回文检测
        bools[i] = huiwenCheck(subS, tempLen, k);
    }

    return bools;
}

int main() {

    char *s = "helloworld";
    int** queries = malloc(sizeof(int*) * 3);
    int* queryOne = malloc(sizeof(int) * 3);
    queryOne[0] = 3;
    queryOne[1] = 6;
    queryOne[2] = 1;
    queries[0] = queryOne;

    int querySize = 1;

    canMakePaliQueries(s, queries, 1, &querySize, &querySize);

    return 0;
}