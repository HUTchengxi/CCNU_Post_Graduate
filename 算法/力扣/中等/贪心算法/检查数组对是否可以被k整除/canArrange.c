#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool canArrange(int *arr, int arrSize, int k) {
    int *mod = (int *) malloc(sizeof(int) * k);
    memset(mod, 0, sizeof(int) * k); //数组元素初始值为0
    for (int i = 0; i < arrSize; i++) {
        mod[(arr[i] % k + k) % k]++;
    }

    for (int i = 1; i <= k / 2; i++) {
        if (mod[i] != mod[k - i])
            return false;
    }

    return mod[0] % 2 == 0;
}

int main() {

    return 0;
}