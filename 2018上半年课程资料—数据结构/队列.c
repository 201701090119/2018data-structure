#include"stdio.h"
#include"stdlib.h"
#define MAXSIZE 24


typedef struct
{
	int data[MAXSIZE];
	int rear,front;
	int num;
}CSeQueue;

/*
//判断队空算法
int Empty_SeQueue(CSeQueue *q)
{
	if(q->num == 0)return 1;
	else return 0;
}
//构建一个空的循环队
CSeQueue *Init_SeQueue()
{
	CSeQueue *q;
	q = (CSeQueue *)malloc(sizeof(CSeQueue));
	q->front = q->rear = MAXSIZE-1;
	q->num = 0;
	return q;
}
*/

//入队
int In_SeQueue(CSeQueue *q,int x)
{
	if(q->num == MAXSIZE)
	{
		printf("队满");
		return -1;
	}
	else
	{
		q->rear = (q->rear+1)%MAXSIZE;
		q->data[q->rear] = x;
		q->num++;
		return 1;
	}
}


//出队
int Out_SeQueue(CSeQueue *q)
{
	if(q->num == 0)
	{
		printf("队空");return -1;
	}
	else{
		q->front = (q->front+1)%MAXSIZE;
		q->data[q->front];
		q->num--;
		return q->data[q->front];
	}
}



int main()
{
	int i;
	int a;
	//char c;
	CSeQueue *q;
	q = (CSeQueue *)malloc(sizeof(CSeQueue));
	q->front = q->rear = MAXSIZE-1;
	q->num = 0;
	do{
		printf("请输入你要入队的数(输入9时终止循环）：");
		scanf("%d",&i);
		In_SeQueue(q,i);
	}while(i!=9);
	printf("所输入元素依次出队\n");
	while(q->num != 0)
	{
	a = Out_SeQueue(q);
	printf("%d\n",a);
	}
	return 0;
}




	