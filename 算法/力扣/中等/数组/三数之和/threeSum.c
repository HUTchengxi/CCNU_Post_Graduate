#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printArray(int* nums, int numSize) {

    printf("------------------------------------------------\n");
    for(int i=0; i<numSize; i++) {
        printf("%d\t", nums[i]);
    }
    printf("\n------------------------------------------------\n");
}

bool search(int* nums, int key, int start, int end) {

    for(int i=start+1; i<end; i++) {
        if(nums[i] == key) {
            return true;
        }
    }
    return false;
}

int partition(int* nums, int left, int right) {

    int temp = nums[left];

    while(left < right) {

        while(left < right && nums[right] >= temp) {
            right--;
        }
        nums[left] = nums[right];

        while(left < right && nums[left] <= temp) {
            left++;
        }
        nums[right] = nums[left];
    }

    nums[left] = temp;
    return left;
}

void quickSort(int* nums, int left, int right) {

    if(left < right) {
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid-1);
        quickSort(nums, mid+1, right);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    if(numsSize < 3) {
        return NULL;
    }

    quickSort(nums, 0, numsSize-1);

    int** results = malloc(sizeof(int*) * numsSize * (numsSize-1) * (numsSize-2));
    int* result = malloc(sizeof(int) * 3);
    int resultLen = 0;
    for(int i=0; i<numsSize; i++) {
        if(i != 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for(int j=numsSize-1; j>1; j--){
            int three = -(nums[i] + nums[j]);
            // »•÷ÿ≤È—Ø
            if(search(nums, three, i, j)) {
                result[0] = nums[i];
                result[1] = nums[j];
                result[2] = three;
                results[resultLen++] = result;
            }
        }
    }

    return results;

}

int main() {

    int numSize = 6, returnSize = 3;
    int* nums = malloc(sizeof(int) * numSize);
    nums[0] = -1;
    nums[1] = 0;
    nums[2] = 1;
    nums[3] = 2;
    nums[4] = -1;
    nums[5] = 4;

    threeSum(nums, numSize, &returnSize, &nums);

    return 0;
}