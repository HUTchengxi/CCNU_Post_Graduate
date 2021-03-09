#include<stdio.h>
int main() {
	
	int non_fibonacci(int);
	
	printf("please input n: ");
	int n;
	scanf("%d", &n);
	printf("non_fibonacci result is: %d\n", non_fibonacci(n));
	printf("...");  // 运行exe程序防止直接退出 
	return 0;
}

int non_fibonacci(int n) {
	
	if(n < 0) {
		return -1;
	}
	if(n < 2) {
		return n;
	}
	
	int results[n+1], i;
	results[0] = 0;   // 如果只初始化results[1] = 1 则 results[0] = 1 
	results[1] = 1;
	for(i=2; i<=n; i++) {
		results[i] = results[i-1] + results[i-2];
	}
	 
	return results[n];
}
