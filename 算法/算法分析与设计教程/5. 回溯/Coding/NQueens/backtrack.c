#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int len, char *desc) {
	
	int i;
	printf("%s\n", desc);
	for(i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void printResults(int n,char **results) {
	
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%c\t", results[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void backtrack(int n, int *affirm, int diagonalZ[], int diagonalF[], int columns[], char** results) {
	
	if(*affirm == n) {
		
		printResults(n, results);
		return;
	}
	
	int i;
	for(i = 0; i < n; i++) {
		
		if(diagonalF[i + *affirm] == 1 || diagonalZ[i > *affirm ? i - *affirm : (*affirm - i) * n] == 1 || columns[i] == 1) {
			continue;
		}
		
		diagonalF[i + *affirm] = 1;
		diagonalZ[i > *affirm ? i - *affirm : (*affirm - i) * n] = 1;
		columns[i] = 1;
		results[*affirm][i] = 'Q';
		
//		printArray(diagonalZ, n*n,"Z");
//		printArray(diagonalF, 2*n-1, "F");
//		printArray(columns, n, "C");
//		printf("i = %d, affirm1 = %d\n", i, *affirm);
		
		*affirm += 1;
		backtrack(n, affirm, diagonalZ, diagonalF, columns, results);
		*affirm -= 1;
		diagonalF[i + *affirm] = 0;
		diagonalZ[i > *affirm ? i - *affirm : (*affirm - i) * n] = 0;
		columns[i] = 0;
		results[*affirm][i] = '*';
		
//		printArray(diagonalZ, n,"AZ");
//		printArray(diagonalF, 2*n-1, "AF");
//		printArray(columns, n, "AC");
		
	}
}

int main() {
	
	int n, i, j;
	printf("please input queen count: ");
	scanf("%d", &n);
	
	int affirm = 0;
	
	int diagonalZ[n*n];
	int diagonalF[2*n-1];
	for(i = 0; i < 2*n-1; i++) {
		diagonalF[i] = 0;
	}
	for(i = 0; i < n*n; i++) {
		diagonalZ[i] = 0;
	}
	
	int columns[n];
	for(i = 0; i < n; i++) {
		columns[i] = 0;
	}
	
	char **results;
	results = (char**) malloc(n*sizeof(char*));
	for(i=0;i<n;i++){
		*(results+i)=(char*)malloc(n*sizeof(char));	
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			results[i][j] = '*';
		}
	}
	
	backtrack(n, &affirm, diagonalZ, diagonalF, columns, results);
	
	return 0;
}
