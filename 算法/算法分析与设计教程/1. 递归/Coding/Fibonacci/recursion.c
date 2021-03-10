#include<stdio.h>
int main() {
	
	int fibonacci(int);
	
	printf("please input n: ");
	int n;
	scanf("%d", &n);
	printf("fibonacci result is: %d", fibonacci(n));
	printf("...");  // 运行exe程序防止直接退出 
	return 0;
}

int fibonacci(int n) {
	
	if(n < 0) {
		return -1;
	}
	if(n < 2) {
		return n;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}
