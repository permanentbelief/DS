#define _CRT_SECURE_NO_WARNINGS 1 


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define INT_MAX
#define MAX_VERTEX_NUM 20
typedef int ElemType;
typedef int AdjMatrix;
typedef int Status;
int book[MAX_VERTEX_NUM] = { 0 };
typedef struct{
	ElemType  vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
}Gragh;
typedef ElemType QElemType;
typedef struct queue{
	QElemType *base;
	int front; //指示队头位置
	int rear;  //指示队尾位置
}SqQueue;

void initQueue(SqQueue *q){
	q->base = (QElemType*)malloc(100 * sizeof(QElemType));
	q->front = q->rear = 0;
}

void enQueue(SqQueue *q, QElemType e){
	q->base[q->rear] = e;
	if (q->rear + 1 == 100){
		q->rear = 0;
	}
	else
		q->rear++;
}

void deQueue(SqQueue *q, QElemType *e){
	*e = q->base[q->front];
	if (q->front + 1 == 100){
		q->front = 0;
	}
	else
		q->front++;
}

void initGragh(Gragh *g){
	g->vexnum = 0;
	g->arcnum = 0;
	for (int i = 0; i<MAX_VERTEX_NUM; i++){
		g->vexs[i] = 0;
		for (int j = 0; j<MAX_VERTEX_NUM; j++){
			g->arcs[i][j] = 0;
		}
	}
}
int local(Gragh g, int n){//值为n的点在定点向量中的下标 
	for (int i = 1; i <= g.vexnum; i++){
		if (g.vexs[i] == n || g.vexs[i] == 0)
			return i;
		else if (i == g.vexnum - 1){
			return g.vexnum;
		}
	}
}
void set(Gragh *g, int a){//赋值 
	for (int i = 1; i <= g->vexnum; i++){
		if (g->vexs[i] == 0 || g->vexs[i] == a){
			g->vexs[i] = a;
			return;
		}
	}
}
void createGragh(Gragh *g){
	printf("请分别输入图的顶点个数，边数：\n");
	int n, m, a, b;
	scanf("%d %d", &n, &m);

	g->vexnum = n;
	g->arcnum = m;
	for (int i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		set(g, a);
		set(g, b);
		g->arcs[local(*g, a)][local(*g, b)] = 1;//无向图 
		g->arcs[local(*g, b)][local(*g, a)] = 1;
	}
}
void print(Gragh g){//打印图 
	printf("\n----------------------\n");
	printf("顶点数： %d\n", g.vexnum);
	printf("边数： %d\n", g.arcnum);
	printf("邻接矩阵：\n   ");
	for (int j = 1; j <= g.vexnum; j++){
		printf("%d ", g.vexs[j]);
	}
	printf("\n   ");
	for (int j = 1; j <= g.vexnum; j++){
		printf("* ");

	}
	printf("\n");
	for (int i = 1; i <= g.vexnum; i++){
		printf("%d *", g.vexs[i]);
		for (int j = 1; j <= g.vexnum; j++){
			printf("%d ", g.arcs[i][j]);
		}
		printf("\n");
	}
	printf("----------------------\n");
}
/*深度优先遍历*/
void dfs(Gragh g, int n, int a){
	int m = local(g, a);
	printf("%d ", g.vexs[m]);
	book[m] = 1;
	if (n == g.vexnum + 1) return;
	for (int i = 1; i <= g.vexnum; i++){
		if (book[i] == 0 && g.arcs[m][i] == 1){
			book[i] = 1;
			dfs(g, ++n, g.vexs[i]);
		}
	}
}


int main(){
	Gragh g;
	initGragh(&g);
	createGragh(&g);
	printf("\n----------------------\n深度优先遍历：\n");
	dfs(g, 1, 1);// g：图 1：第一步  1：从顶点值为1的地方开始遍历 
	//printf("\n----------------------\n广度优先遍历：\n");
	//bfs(g, 1);// g:图   1:从定点值为1的地方开始遍历 
	print(g);
	system("pause");
	return 0;
}