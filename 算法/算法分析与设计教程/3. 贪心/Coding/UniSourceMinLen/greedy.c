//
// Created by Jream.Y on 2021/3/11.
//
#include <stdio.h>
#include <stdlib.h>

#define INFINITE 10000000
#define LEN 6

// 二维数组形式存储有向带权图 
int graph[LEN][LEN];

int weightArray[] = {5, INFINITE, 20, 9, INFINITE, 12, 17, INFINITE, 33, 26};

int randWeight() {
	
	return rand() % 10;
}

void initGraph() {
	
	int i, j;
	for(i = 0; i<LEN; i++) {
		for(j = 0; j<LEN; j++) {
			if(i == j) {
				graph[i][j] = 0;
				continue;
			}
			graph[i][j] = INFINITE;
		}
	}
	
	graph[0][1] = 6;
	graph[0][3] = 9;
	graph[1][2] = 1;
	graph[1][5] = 4;
	graph[2][3] = 1;
	graph[2][4] = 2;
	graph[3][4] = 2;
	graph[4][5] = 1;
}

void printGraph() {
	
	int i,j;
	for(i=0; i<LEN; i++) {
		for(j=0; j<LEN; j++) {
			printf("%8d\t", graph[i][j]);
		}
		printf("\n");
	}
}

int dist[LEN];   // 各点最短路径 

// 源点，第一个点 
void initDist() {
	
	int i;
	for(i = 0; i<LEN; i++) {
		dist[i] = graph[0][i];
	}
}

void printDist() {
	
	int i;
	for(i = 0; i<LEN; i++) {
		printf("%d\t", dist[i]);
	}
	printf("\n");
}

int flag[LEN];    // 0待计算，1已完成 

void initFlag() {
	
	int i;
	flag[0] = 1;
	for(i = 1; i<LEN; i++) {
		flag[i] = 0;
	}
}

void printFlag() {
	
	int i;
	for(i = 0; i<LEN; i++) {
		printf("%d\t", flag[i]);
	}
	printf("\n");
}

int next[LEN];   //各汇点最短路径前一跳顶点位置 

void initNext() {
	
	int i;
	for(i = 0; i<LEN; i++) {
		next[i] = 0;
	}
}

void printNext() {
	
	int i;
	for(i = 0; i<LEN; i++) {
		printf("%d\t", next[i]);
	}
	printf("\n");
}

void greedy() {
	
	int i=1;
	int searchIndex = 0;
	while(i++ != LEN) {
		
		// 找到待完成的顶点中距离源点最小的顶点
		int min = INFINITE;
		int index = 0;
		for(searchIndex = 1; searchIndex < LEN; searchIndex++) {
			if(flag[searchIndex] == 1) {
				continue;
			}
			if(min > dist[searchIndex]) {
				min = dist[searchIndex];
				index = searchIndex;
			}
		}
		
		printf("min = %d, index = %d\n", min, index);
		
		// 更新dist和next 
		int j;
		for(j = 1; j < LEN; j++) {
			if(j != index && graph[index][j] != INFINITE && dist[j] > dist[index] + graph[index][j]) {
				dist[j] = dist[index] + graph[index][j];
				next[j] = index;
			}
		} 
		
		// 更新flag
		flag[index]++;
	}
}

int main() {
	
	initGraph();
	
	printf("init graph: \n");
	printGraph();
	
	initDist();
	
	printf("init dist: \n");
	printDist();
	
	initFlag();
	
	printf("init flag: \n");
	printFlag();
	
	initNext();
	
	printf("init next: \n");
	printNext();
	
	printf("\n\n");
	
	greedy();
	
	printf("calculate dist: \n");
	printDist();
	
	printf("calculate flag: \n");
	printFlag();
	
	printf("calculate next: \n");
	printNext();
	
    return 0;
}
