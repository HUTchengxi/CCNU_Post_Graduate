#include<stdio.h>
int main() {
	
	int n;
	printf("please input goods count: ");
	scanf("%d", &n);
	
	int w[n+1];
	int v[n+1];
	
	int i, j;
	for(i = 1; i <= n; i++) {
		printf("please input goods[%d]'s weight: ", i);
		scanf("%d", &w[i]);
		printf("please input goods[%d]'s value: ", i);
		scanf("%d", &v[i]);
	}
	
	int capacity;
	printf("please input package capacity: ");
	scanf("%d", &capacity);
	
	int V[n+1][capacity];
	
	// init
	for(i = 0; i <= n; i++) {
		V[i][0] = 0;
	}
	for(j = 0; j <= capacity; j++) {
		V[0][j] = 0;
	}
	
	// state trans formula
	for(j = 1; j<=capacity; j++) {   // capacity
		for(i = 1; i<=n; i++) {   // goods
			if(j < w[i]) {
				V[i][j] = V[i-1][j];
				continue;
			}
			V[i][j] = V[i-1][j] > V[i-1][j-w[i]] + v[i] ? V[i-1][j] : V[i-1][j-w[i]] + v[i];
		}
	}
	
	printf("the max value is: %d\n", V[n][capacity]);
	printf("...");
	
	return 0;
}
