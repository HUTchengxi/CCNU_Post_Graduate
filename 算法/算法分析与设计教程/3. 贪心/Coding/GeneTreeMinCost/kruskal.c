#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX         100                 // �����������
#define INF         (~(0x1<<31))        // ���ֵ(��0X7FFFFFFF)
#define isLetter(a) ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)   (sizeof(a)/sizeof(a[0]))

// �ڽӾ���
typedef struct _graph
{
    char vexs[MAX];       // ���㼯��
    int vexnum;           // ������
    int edgnum;           // ����
    int matrix[MAX][MAX]; // �ڽӾ���
}Graph, *PGraph;

// �ߵĽṹ��
typedef struct _EdgeData
{
    char start; // �ߵ����
    char end;   // �ߵ��յ�
    int weight; // �ߵ�Ȩ��
}EData;


/*
 * ����ch��matrix�����е�λ��
 */
static int get_position(Graph G, char ch)
{
    int i;
    for(i=0; i<G.vexnum; i++)
        if(G.vexs[i]==ch)
            return i;
    return -1;
}

/*
 * ��ȡһ�������ַ�
 */
static char read_char()
{
    char ch;

    do {
        ch = getchar();
    } while(!isLetter(ch));

    return ch;
}

/*
 * ����ͼ(�����ṩ�ľ���)
 */
Graph* create_example_graph()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int matrix[][9] = {
             /*A*//*B*//*C*//*D*//*E*//*F*//*G*/
      /*A*/ {   0,  12, INF, INF, INF,  16,  14},
      /*B*/ {  12,   0,  10, INF, INF,   7, INF},
      /*C*/ { INF,  10,   0,   3,   5,   6, INF},
      /*D*/ { INF, INF,   3,   0,   4, INF, INF},
      /*E*/ { INF, INF,   5,   4,   0,   2,   8},
      /*F*/ {  16,   7,   6, INF,   2,   0,   9},
      /*G*/ {  14, INF, INF, INF,   8,   9,   0}};
    int vlen = LENGTH(vexs);
    int i, j;
    Graph* pG;
    
    // ����"������"��"����"
    if ((pG=(Graph*)malloc(sizeof(Graph))) == NULL )
        return NULL;
    memset(pG, 0, sizeof(Graph));

    // ��ʼ��"������"
    pG->vexnum = vlen;
    // ��ʼ��"����"
    for (i = 0; i < pG->vexnum; i++)
        pG->vexs[i] = vexs[i];

    // ��ʼ��"��"
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            pG->matrix[i][j] = matrix[i][j];

    // ͳ�Ʊߵ���Ŀ
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            if (i!=j && pG->matrix[i][j]!=INF)
                pG->edgnum++;
    pG->edgnum /= 2;

    return pG;
}

/*
 * ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
 */
static int first_vertex(Graph G, int v)
{
    int i;

    if (v<0 || v>(G.vexnum-1))
        return -1;

    for (i = 0; i < G.vexnum; i++)
        if (G.matrix[v][i]!=0 && G.matrix[v][i]!=INF)
            return i;

    return -1;
}

/*
 * ���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
 */
static int next_vertix(Graph G, int v, int w)
{
    int i;

    if (v<0 || v>(G.vexnum-1) || w<0 || w>(G.vexnum-1))
        return -1;

    for (i = w + 1; i < G.vexnum; i++)
        if (G.matrix[v][i]!=0 && G.matrix[v][i]!=INF)
            return i;

    return -1;
}

/*
 * ��ӡ�������ͼ
 */
void print_graph(Graph G)
{
    int i,j;

    printf("Martix Graph:\n");
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            printf("%10d ", G.matrix[i][j]);
        printf("\n");
    }
}

/* 
 * ��ȡͼ�еı�
 */
EData* get_edges(Graph G)
{
    int i,j;
    int index=0;
    EData *edges;

    edges = (EData*)malloc(G.edgnum*sizeof(EData));
    for (i=0;i < G.vexnum;i++)
    {
        for (j=i+1;j < G.vexnum;j++)
        {
            if (G.matrix[i][j]!=INF)
            {
                edges[index].start  = G.vexs[i];
                edges[index].end    = G.vexs[j];
                edges[index].weight = G.matrix[i][j];
                index++;
            }
        }
    }

    return edges;
}

/* 
 * �Ա߰���Ȩֵ��С��������(��С����)
 */
void sorted_edges(EData* edges, int elen)
{
    int i,j;

    for (i=0; i<elen; i++)
    {
        for (j=i+1; j<elen; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                // ����"��i����"��"��j����"
                EData tmp = edges[i];
                edges[i] = edges[j];
                edges[j] = tmp;
            }
        }
    }
}

/*
 * ��ȡi���յ�
 */
int get_end(int vends[], int i)
{
    while (vends[i] != 0)
        i = vends[i];
    return i;
}

/*
 * ��³˹������Kruskal)��С������
 */
void kruskal(Graph G)
{
    int i,m,n,p1,p2;
    int length;
    int index = 0;          // rets���������
    int vends[MAX]={0};     // ���ڱ���"������С������"��ÿ�������ڸ���С���е��յ㡣
    EData rets[MAX];        // ������飬����kruskal��С�������ı�
    EData *edges;           // ͼ��Ӧ�����б�

    // ��ȡ"ͼ�����еı�"
    edges = get_edges(G);
    // ���߰���"Ȩ"�Ĵ�С��������(��С����)
    sorted_edges(edges, G.edgnum);

    for (i=0; i<G.edgnum; i++)
    {
        p1 = get_position(G, edges[i].start);   // ��ȡ��i���ߵ�"���"�����
        p2 = get_position(G, edges[i].end);     // ��ȡ��i���ߵ�"�յ�"�����

        m = get_end(vends, p1);                 // ��ȡp1��"���е���С������"�е��յ�
        n = get_end(vends, p2);                 // ��ȡp2��"���е���С������"�е��յ�
        // ���m!=n����ζ��"��i"��"�Ѿ���ӵ���С�������еĶ���"û���γɻ�·
        if (m != n)
        {
            vends[m] = n;                       // ����m��"���е���С������"�е��յ�Ϊn
            rets[index++] = edges[i];           // ������
        }
    }
    free(edges);

    // ͳ�Ʋ���ӡ"kruskal��С������"����Ϣ
    length = 0;
    for (i = 0; i < index; i++)
        length += rets[i].weight;
    printf("Kruskal=%d: ", length);
    for (i = 0; i < index; i++)
        printf("(%c,%c) ", rets[i].start, rets[i].end);
    printf("\n");
}

void main()
{
    Graph* pG;

    pG = create_example_graph();

    kruskal(*pG);             // kruskal�㷨������С������
}
