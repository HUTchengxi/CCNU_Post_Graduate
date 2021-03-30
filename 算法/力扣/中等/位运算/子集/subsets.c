#include<stdio.h>
#include<Stdlib.h>
#include<String.h>

/**
 * 使用二进制的思想，0和1分别表示选与不选
 * @param nums
 * @param numsSize
 * @param returnSize
 * @param returnColumnSizes
 * @return
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(sizeof(int*) * (1 << numsSize));
    *returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
    *returnSize = 1 << numsSize;
    int t[numsSize];
    for (int mask = 0; mask < (1 << numsSize); ++mask) {
        int tSize = 0;
        for (int i = 0; i < numsSize; ++i) {
            if (mask & (1 << i)) {
                t[tSize++] = nums[i];
            }
        }
        int* tmp = malloc(sizeof(int) * tSize);
        memcpy(tmp, t, sizeof(int) * tSize);
        (*returnColumnSizes)[mask] = tSize;
        ans[mask] = tmp;
    }
    return ans;
}

int main() {

    return 0;
}