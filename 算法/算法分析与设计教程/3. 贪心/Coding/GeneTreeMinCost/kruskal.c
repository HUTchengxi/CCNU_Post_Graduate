#include<stdio.h> 
#include<stdbool.h>

// ±ß
typedef struct Edge {
	int start;
	int end;
	int weight;
} Edge;

#define ELEN 11
#define VLEN 7

Edge edges[ELEN];
char vexFlag[VLEN] = {'A','B','C','D','E','F','G'};
int team[ELEN];

bool edgeCompare(Edge bigEdge, Edge smallEdge) {
	
	return bigEdge.weight >= smallEdge.weight;
}

int partition(int left, int right) {
	
	Edge temp = edges[left];
	
	while(left < right) {
		
		while(left < right && edgeCompare(edges[right], temp)) {
			right--;
		}
		edges[left] = edges[right];
		
		while(left < right && edgeCompare(temp, edges[left])) {
			left++;
		}
		edges[right] = edges[left];
	}
	edges[left] = temp;
	return left;
}

void quickSort(int left, int right) {
	
	if(left < right) {
		
		int mid = partition(left, right);
		quickSort(left, mid-1);
		quickSort(mid+1, right);
	}
}

void sortByWeightDecrease() {
	
	quickSort(0, ELEN-1);
}

void initEdge() {
	
	edges[0].start = 0;
	edges[0].end = 1;
	edges[0].weight = 12;
	
	edges[1].start = 0;
	edges[1].end = 5;
	edges[1].weight = 16;
	
	edges[2].start = 0;
	edges[2].end = 6;
	edges[2].weight = 14;
	
	edges[3].start = 1;
	edges[3].end = 5;
	edges[3].weight = 7;
	
	edges[4].start = 1;
	edges[4].end = 2;
	edges[4].weight = 10;
	
	edges[5].start = 2;
	edges[5].end = 5;
	edges[5].weight = 6;
	
	edges[6].start = 2;
	edges[6].end = 3;
	edges[6].weight = 3;
	
	edges[7].start = 3;
	edges[7].end = 4;
	edges[7].weight = 4;
	
	edges[8].start = 4;
	edges[8].end = 5;
	edges[8].weight = 2;
	
	edges[9].start = 4;
	edges[9].end = 6;
	edges[9].weight = 8;
	
	edges[10].start = 5;
	edges[10].end = 6;
	edges[10].weight = 9;
	
	int i;
	for(i = 0; i < ELEN; i++) {
		team[i] = -1;
	}
}

int leader(vexNum) {
	if(team[vexNum] != -1 && team[vexNum] != vexNum) {
		return leader(team[vexNum]);
	}
	return vexNum;
}

bool isDifferTeam(int vexOne, int vexTwo) {
	return leader(vexOne) != leader(vexTwo);
}

void beSameTeam(int start, int end) {
	team[leader(end)] = leader(start);
}

void kruskal() {
	
	int edgeVisitIdx = 0;
	int minWeight = 0;
	bool compareFlag = true;
	while(true) {
		
		compareFlag = true;
		int idx;
		for(idx = edgeVisitIdx; idx < ELEN; idx++) {
			
			edgeVisitIdx++;
			int startVex = edges[idx].start;
			int endVex = edges[idx].end;
			if(!isDifferTeam(startVex, endVex)) {
				continue;
			}
			minWeight += edges[idx].weight;
			beSameTeam(startVex, endVex);
			printf("{%c, %c, %d}\n", vexFlag[startVex], vexFlag[endVex], edges[idx].weight);
			compareFlag = false;
			break;
		}
		if(compareFlag) {
			printf("minWeight is %d\n", minWeight);
			return;
		}
	}
} 

int main() {
	
	initEdge();
	
	sortByWeightDecrease();

	kruskal();	
	
	return 0;
}
