#include<stdio.h>

char a = 'a', b = 'b', c = 'c';

void hanoiCore(int n, char a, char b, char c, int *result) {
	
	if(n == 1) {
		*result = *result + 1;
		return;
	} 
	
	hanoiCore(n-1, a, c, b, result);
	*result = *result + 1;
	hanoiCore(n-1, b, a, c, result);
	
}

int hanoi(int n) {
	
	if(n < 0) {
		return -1;
	}
	if(n == 0) {
		return 0;
	}
	
	int result = 0;
	hanoiCore(n, a, b, c, &result);
	return result;
}

int main() {
	
	printf("please input n: ");
	int n;
	scanf("%d", &n);
	printf("hanoi result is: %d\n", hanoi(n));
	printf("...");  // 运行exe程序防止直接退出 
	return 0;
}
