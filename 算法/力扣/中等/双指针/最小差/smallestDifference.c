#include<stdio.h>

long long absMinus(long long a, long long b) {
    return a > b ? a-b : b-a;
}

int partition(int *arr, int left, int right) {

    int temp = arr[left];
    while(left < right) {

        while(left<right && arr[right] > temp) {
            right--;
        }
        arr[left] = arr[right];

        while(left<right && arr[left] < temp) {
            left++;
        }
        arr[right] = arr[left];
    }

    arr[left] = temp;
    return left;
}

void quickSort(int *arr, int left, int right) {

    if(left < right) {
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid-1);
        quickSort(arr, mid+1, right);
    }
}

int smallestDifference(int* a, int aSize, int* b, int bSize){

    quickSort(b, 0, bSize-1);
    quickSort(a, 0, aSize-1);

    int i, j;

    long long result = 2147483647, temp;
    for(i = 0, j = 0; i < aSize && j < bSize; ) {
        if(a[i] == b[j]) {
            return 0;
        }
        temp = absMinus(a[i], b[j]);
        result = result > temp ? temp : result;
        if(a[i] > b[j]) {
            j++;
            continue;
        }
        i++;
    }

    return result;
}

int main() {

    int a[] = {1,3,15,11,2};
    int b[] = {23,127,235,19,8};
    int aSize= 5;
    int bSize = 5;

    printf("result is %d\n", smallestDifference(a, aSize, b, bSize));
    return 0;
}