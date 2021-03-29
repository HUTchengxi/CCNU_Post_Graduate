#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int minOperations(char **logs, int logsSize) {

    int step = 0;

    char *back = "../";
    char *current = "./";

    for (int i = 0; i < logsSize; i++) {
        if (!strcmp(logs[i], back)) {
            step = step != 0 ? --step : 0;
            continue;
        }
        if (!strcmp(logs[i], current)) {
            continue;
        }
        step++;
    }

    return step;
}

int main() {

    int logsSize = 5;
    char **logs = malloc(sizeof(char *) * logsSize);
    int idx = 0;
    logs[idx++] = "d1/";
    logs[idx++] = "d2/";
    logs[idx++] = "../";
    logs[idx++] = "d21/";
    logs[idx++] = "./";

    printf("%d\n", minOperations(logs, logsSize));
    return 0;
}