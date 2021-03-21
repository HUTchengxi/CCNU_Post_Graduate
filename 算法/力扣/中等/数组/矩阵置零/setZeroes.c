#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define GM 5
#define GN 4

int globalM = GM;
int globalN[] = {GN};

/**
 * 不定义一元数组记录状态，直接使用matrix[i][0]和matrix[0][j]记录
 * @param matrix
 * @param matrixSize
 * @param matrixColSize
 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){

    int m = matrixSize;
    int n = matrixColSize[0];

    bool flag_row = false;
    bool flag_col = false;

    int i, j;

    for(i = 0; i < m; i++) {
        if(matrix[i][0] == 0) {
            flag_col = true;
        }
    }

    for(j = 0; j < n; j++) {
        if(matrix[0][j] == 0) {
            flag_row = true;
        }
    }

    for(i = 1; i < m; i++) {
        for(j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(i = 1; i < m; i++) {
        for(j = 1; j < n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    for(j = 0; j < n; j++) {
        if(matrix[0][j] == 0) {
            for(i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    if(flag_row) {
        for(j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if(flag_col) {
        for(i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

}

/**
 * 简单粗暴的循环遍历形式
 * @param matrix
 * @param matrixSize
 * @param matrixColSize
 */
void setZeroesOne(int** matrix, int matrixSize, int* matrixColSize){

    int m = matrixSize;
    int n = matrixColSize[0];

    // log row change status
    int rows[m];
    // log column change status
    int columns[n];

    memset(rows, 0, sizeof(int) * m);
    memset(columns, 0, sizeof(int) * n);

    int i, j;
    for(i = 0; i < m; i++) {
        if(rows[i] == 1) {
            continue;
        }
        for(j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                rows[i] = 1;
                if(columns[j] == 1) {
                    continue;
                }
                columns[j] = 1;
            }
        }
    }

    for(i = 0; i < m; i++) {
        if(rows[i] == 1) {
            for(j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for(j = 0; j < n; j++) {
        if(columns[j] == 1) {
            for(i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

}

void printMatrix(char *desc, int** matrix) {

    printf(desc);

    for(int i = 0; i < globalM; i++) {
        for(int j = 0; j < globalN[0]; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int** matrix = malloc(sizeof(int*) * GM);

    int i = 0;

    int arr1[] = {0,0,0,5};
    int arr2[] = {4,3,1,4};
    int arr3[] = {0,1,1,4};
    int arr4[] = {1,2,1,3};
    int arr5[] = {0,0,1,1};

    matrix[i++] = arr1;
    matrix[i++] = arr2;
    matrix[i++] = arr3;
    matrix[i++] = arr4;
    matrix[i] = arr5;

    printMatrix("before\n", matrix);

    setZeroes(matrix, globalM, globalN);

    printMatrix("after\n", matrix);

    return 0;
}