#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char binary[1024];

void transToBinary(int n) {

    int idx = 0;
    while (n != 0) {
        binary[idx++] = n % 2 + '0';
        n >>= 1;
    }
    binary[idx--] = '\0';

    for (int j = 0; j < idx; j++, idx--) {
        // 异或三次，等于交换，真棒
        binary[j] ^= binary[idx] ^= binary[j] ^= binary[idx];
    }
}

bool queryString(char *S, int N) {

    if (S == NULL || S[0] == '\0') {
        return false;
    }

    for (int i = 1; i <= N; i++) {
        transToBinary(i);
        if (strstr(S, binary) == NULL) {
            return false;
        }
    }
    return true;
}

int main() {

    printf("%d\n", queryString("0110", 3));
    printf("%d\n", queryString("0110", 4));
    return 0;
}