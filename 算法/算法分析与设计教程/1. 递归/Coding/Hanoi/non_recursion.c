#include<stdio.h>

char a = 'a', b = 'b', c = 'c';

int non_hanoi(int n) {
	
	if(n < 0) {
		return -1;
	}
	if(n == 0) {
		return 0;
	}
	
	int results[n+1], i;
	results[1] = 1;
	for(i = 2; i <= n; i++) {
		results[i] = 2 * results[i-1] + 1;
	}
	return results[n];
}

int main() {
	
	printf("please input n: ");
	int n;
	scanf("%d", &n);
	printf("non_hanoi result is: %d\n", non_hanoi(n));
	printf("...");  // 运行exe程序防止直接退出 
	return 0;
} 
