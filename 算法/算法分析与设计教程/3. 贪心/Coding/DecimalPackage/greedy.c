#include<stdio.h>

#define MAX 100

// 定义结构体来存储物品对应的信息
struct Object {
	
	double value;  // 价值 
	int weight;  // 重量 
	double rate;  // 价值率 
} objs[MAX];

int len;

void printArray() {

	int i;
	for(i = 0; i<len; i++) {
		printf("weight: %d\t", objs[i].weight);
		printf("value: %f\t", objs[i].value);
		printf("rate: %f\n", objs[i].rate);
	}
}

void swap(struct Object objs[], int a, int b) {
	
	struct Object temp = objs[a];
	objs[a] = objs[b];
	objs[b] = temp;
}

int partition(struct Object objs[], int left, int right) {
	
	struct Object tempObj = objs[left];
	double tempRate  = tempObj.rate;
	
	while(left < right) {
		
		while(objs[right].rate < tempRate && left < right) {
			right--;
		}
		objs[left] = objs[right];
		
		while(objs[left].rate > tempRate && left < right) {
			left++;
		}
		objs[right] = objs[left];
	}
	
	objs[left] = tempObj;
	return left;
}

void quickSort(struct Object objs[], int left, int right) {
	
	if(left < right) {
		
		int mid = partition(objs, left, right);
		quickSort(objs, left, mid-1);
		quickSort(objs, mid+1, right);
	}
}

// 将物品按照价值率降序排列
void sortByRate() {
	quickSort(objs, 0, len-1);
}

void greedy() {
	
	printf("please input package weight: ");
	int packageWeight;
	scanf("%d", &packageWeight);
	
	double maxValue = 0;
	int index = 0;
	
	for(index = 0; index < len; index++) {
		
		if(objs[index].weight <= packageWeight) {
			maxValue += objs[index].value;
			packageWeight -= objs[index].weight;
			continue;
		}
		
		maxValue += packageWeight * objs[index].rate;
		break;
	}
	
	printf("maxValue is %f\n", maxValue);
	printf("...");
} 

void initArray() {
	
	int i = 0;
//	for(i=0; i<7; i++) {
//		objs[i].weight = (i + 1) * 10;
//		objs[i].value = i + 10;
//		objs[i].rate = objs[i].value / (objs[i].weight * 1.0);
//		len++;
//	}
	objs[i].weight = 10;
	objs[i].value = 60;
	objs[i].rate = 6.0;
	objs[++i].weight = 20;
	objs[i].value = 100;
	objs[i].rate = 5.0;
	objs[++i].weight = 30;
	objs[i].value = 120;
	objs[i].rate = 4.0;
	len = 3;
}

int main() {
	
	initArray();
	
	printf("init objects：\n");
	printArray();
	
	sortByRate();
	
	greedy();
	
	return 0;
} 
