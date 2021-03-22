#include<stdio.h>
#include<math.h>

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){

    int i, j, k, count = 0;
    for(i = 0; i < arrSize-2; i++) {
        for(j = i+1; j < arrSize-1; j++) {
            if(abs(arr[i] - arr[j]) > a) {
                continue;
            }
            for(k = j+1; k < arrSize; k++) {
                if(abs(arr[j] - arr[k]) > b || abs(arr[i] - arr[k]) > c) {
                    continue;
                }
                count++;
            }
        }
    }

    return count;
}