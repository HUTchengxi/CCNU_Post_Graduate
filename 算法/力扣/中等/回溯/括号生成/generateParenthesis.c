#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXSIZE 2000
void Fill(int index, int right, int left, int n, char *src,char **ret, int* returnSize)
{
    if (index == 2 * n) {
        ret[(*returnSize)] = (char*)malloc(sizeof(char) * (2 * n + 1));
        strcpy(ret[(*returnSize)++], src);
        return;
    }
    if (left < n) {
        src[index] = '(';
        Fill(index + 1, right, left + 1, n, src, ret, returnSize);
    }
    if (right < left) {
        src[index] = ')';
        Fill(index + 1, right + 1, left, n, src, ret, returnSize);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char *src = (char*)malloc(sizeof(char) * (2 * n + 1));
    src[2 * n] = '\0';
    char **ret = (char**)malloc(sizeof(char**) * MAXSIZE);
    *returnSize = 0;
    Fill(0,0,0,n,src,ret,returnSize);
    return ret;
}

int main() {

    return 0;
}