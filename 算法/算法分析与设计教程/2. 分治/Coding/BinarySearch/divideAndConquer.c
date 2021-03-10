#include<stdio.h>
int main() {
	
	int binarySearch(int[], int, int);
	return 0;
}

/**
 * 1£º´æÔÚ
 * 0£º²»´æÔÚ 
 */ 
int binarySearch(int a[], int n, int key) {
	
	int low = 0,
		high = n-1,
		mid;
		
	while(low < high) {
		
		mid = (low + high) / 2;
		if(a[mid] < key) {
			low = mid+1;
			continue;
		}
		if(a[mid] > key) {
			high = mid - 1;
			continue;
		}
		return 1;
	}
	
	return a[low] == key ? 1 : 0;
}
