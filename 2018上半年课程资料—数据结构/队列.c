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
//�ж϶ӿ��㷨
int Empty_SeQueue(CSeQueue *q)
{
	if(q->num == 0)return 1;
	else return 0;
}
//����һ���յ�ѭ����
CSeQueue *Init_SeQueue()
{
	CSeQueue *q;
	q = (CSeQueue *)malloc(sizeof(CSeQueue));
	q->front = q->rear = MAXSIZE-1;
	q->num = 0;
	return q;
}
*/

//���
int In_SeQueue(CSeQueue *q,int x)
{
	if(q->num == MAXSIZE)
	{
		printf("����");
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


//����
int Out_SeQueue(CSeQueue *q)
{
	if(q->num == 0)
	{
		printf("�ӿ�");return -1;
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
		printf("��������Ҫ��ӵ���(����9ʱ��ֹѭ������");
		scanf("%d",&i);
		In_SeQueue(q,i);
	}while(i!=9);
	printf("������Ԫ�����γ���\n");
	while(q->num != 0)
	{
	a = Out_SeQueue(q);
	printf("%d\n",a);
	}
	return 0;
}




	