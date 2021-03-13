#include<stdio.h>
#include<math.h>
int main() {
	
	int n;
	while(n != -1) {
		printf("please input rope len: ");
		scanf("%d", &n);
		
		
		float maxMultiply = n <= 3 ? n-1 : pow(3, n/3-1) * (n%3==0 ? 3 : n%3==1 ? 4 : 6);
		printf("max multiply result is %d\n", (int)maxMultiply);
		printf("...");
	}
	
	return 0;
}
