#include<stdio.h> 
#include<string.h>
#define LEN 100
int main() {
	
	char str1[LEN], str2[LEN];
	
	while(scanf("%s%s", str1, str2)) {
		
		int m = strlen(str1);
		int n = strlen(str2);
		
		if(m == 0 || n == 0) {
			printf("go to end...");
			return 0;
		}
		
		int dp[m][n];
		char results[n > m ? n : m];
		int count = 0;
		
		// init
		int i, j;
		if(str1[0] == str2[0]) {
			dp[0][0] = 1;
			results[count++] = str1[0];
		} else {
			dp[0][0] = 0;	
		}
		for(i = 0; i < m; i++) {
			dp[i][0] = dp[0][0];
		}
		for(j = 0; j < n; j++) {
			dp[0][j] = dp[0][0];
		}
		
		// state trans formula
		for(i = 1; i < m; i++) {
			for(j = 1; j < n; j++) {
				if(str1[i] == str2[j]) {
					dp[i][j] = dp[i-1][j-1] + 1;
					results[count++] = str1[i];
					continue;
				}
				dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
			}
		}
		
		printf("lcs result is %s\nlcs len is %d\n", results, count);
		
	}
	
	return 0;
}
