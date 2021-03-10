#include<stdio.h>

int main() {
	
	void quickSort(int[], int, int);
	int partition(int[], int, int);
	
	int n;
	printf("please input array len: ");
	scanf("%d", &n);
	
	int i, a[n];
	for(i = 0; i < n ; i++) {
		printf("please input a[%d] value: ", i);
		scanf("%d", &a[i]);
	}
	
	quickSort(a, 0, n-1);
	
	printf("after quickSort, the array list: \n");
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n...");
	
	return 0;
}

void quickSort(int a[], int left, int right) {
	
	if(left < right) {
		
		int mid = partition(a, left, right);
		quickSort(a, left, mid-1);
		quickSort(a, mid+1, right);
	}
}

int partition(int a[], int left, int right) {
	
	int temp = a[left];
	
	while(left < right) {
		
		while(a[right] > temp && right > left) {
			right--;
		}
		a[left] = a[right];
		
		while(a[left] < temp && left < right) {
			left++;
		}
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}

