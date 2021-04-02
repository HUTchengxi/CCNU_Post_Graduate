#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int *runningSum(int *nums, int numsSize, int *returnSize) {

    // 使用 returnSize = &numSize; 就不能得到正确的结果，不知道为啥
    *returnSize = numsSize;
    if (numsSize <= 1) {
        return nums;
    }

    int *rets = malloc(sizeof(int) * numsSize);

    rets[0] = nums[0];
    for(int i=1; i<numsSize; i++) {
        rets[i] = rets[i-1] + nums[i];
    }

    return rets;
}

int main() {

    int numSize = 4;
    int nums[] = {1,2,3,4};
    int *rets = runningSum(nums, numSize, &numSize);

    for(int i=0; i<numSize; i++) {
        printf("%d\t", rets[i]);
    }
    return 0;
}