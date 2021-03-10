#include<stdio.h>

int main() {
	
	int greatCommonDivisor(int, int); 
	
	printf("please input m: ");
	int m;
	scanf("%d", &m);
	printf("please input n: ");
	int n;
	scanf("%d", &n);
	printf("recursion result is: %d\n", greatCommonDivisor(m, n));
	printf("...");  // ����exe�����ֱֹ���˳� 
	return 0;
}

int greatCommonDivisor(int m, int n) {
	
	if(m < n) {
		return greatCommonDivisor(n, m);
	}
	
	if(n == 0) {
		return m;
	}
	
	return greatCommonDivisor(n, m%n);
}




