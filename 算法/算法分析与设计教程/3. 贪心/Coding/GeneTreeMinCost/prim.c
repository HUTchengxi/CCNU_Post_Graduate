#include <stdio.h>

#define MAX_INT (int)((unsigned)(-1) >> 1)
#define MIN(x, y) ((x)>(y))?(y):(x)

#define TRUE 1
#define FALSE 0

#define  N 6

struct item {
    int s;
    int v;
    int cost;
} closedge[N];
int pc = 0;

int a[N+1][N+1];
int s_set[N+1], s_count;
int vs_set[N+1], vs_count;


void createMatrix();
void init(int s);
void prim();

int main()
{
    int i, j, s;

    createMatrix();

    for(i=1; i<=N; i++) {
        for(j=1; j<=N; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }

    printf("start node:");
    scanf("%d", &s);
    if(s>=1 && s<=N) {
        init(s);
    } else {
        printf("input error!\n");
        return -1;
    }

    prim();

    printf("result:\n");
    for(i=0; i<pc; i++) {
        printf("%4d%4d %4d\n", closedge[i].s, closedge[i].v, closedge[i].cost);
    }

    return 0;
}

void prim()
{
    int i, j, minval, pi, pj;

    for(;;) {
        if(vs_count == 0)
            return;

        minval=MAX_INT;
        for(i=1; i<=N; i++) {
            if(s_set[i]) {
                for(j=1; j<=N; j++) {
                    if(i!=j && vs_set[j]) {
                        if(a[i][j] != -1 && a[i][j] < minval) {
                            minval = a[i][j];
                            pi = i;
                            pj = j;
                        }
                    }
                }
            }
        }
        s_set[pj] = TRUE;
        s_count++;
        vs_set[pj] = FALSE;
        vs_count--;

        closedge[pc].s = pi;
        closedge[pc].v = pj;
        closedge[pc].cost = minval;
        pc++;
    }
}

//´´½¨ÁÚ½Ó¾ØÕó
void createMatrix()
{
    int i, j;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            if(i==j)
                a[i][j] = 0;
            else
                a[i][j] = -1;

    FILE *fp;
    fp = fopen("p1.txt", "r");

    for(;;) {
        int val;
        fscanf(fp, "%d%d%d", &i, &j, &val);
        if(i == -1)
            break;
        a[i][j] = val;
        a[j][i] = val;
    }
    fclose(fp);
}

void init(int s)
{
    int i;

    for(i=1; i<=N; i++) {
        s_set[i] = FALSE;
        vs_set[i] = TRUE;
    }
    s_set[s] = TRUE;
    s_count = 1;
    vs_set[s] = FALSE;
    vs_count = N-1;
}
