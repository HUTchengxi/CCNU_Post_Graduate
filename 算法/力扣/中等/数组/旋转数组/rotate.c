#include<stdio.h>
#include<Stdlib.h>
#include<String.h>
#include<stdbool.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b, *b = t;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start += 1;
        end -= 1;
    }
}
/**
 * 分两块进行数组翻转
 * @param nums
 * @param numsSize
 * @param k
 */
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

/**
 * 旋转数组:普通旋转
 * @param nums
 * @param numsSize
 * @param k
 */
void rotate2(int *nums, int numsSize, int k) {

    if (k == 0 || numsSize <= 1) {
        return;
    }

    int *temp = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        nums[(i + k) % numsSize] = temp[i];
    }

    for (int i = 0; i < numsSize; i++) {
        printf("%d\t", nums[i]);
    }
}

int main() {

    int numSize = 7;
    int *nums = malloc(sizeof(int) * numSize);
    int i = 0;
    nums[i++] = 1;
    nums[i++] = 2;
    nums[i++] = 3;
    nums[i++] = 4;
    nums[i++] = 5;
    nums[i++] = 6;
    nums[i++] = 7;
    rotate(nums, numSize, 3);
    return 0;
}