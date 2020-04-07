#include<stdio.h>
#include<malloc.h>
typedef struct lnode
{
	int data;
	struct lnode*next;
}LNode,*LinkList;

void print_list(LNode *pListHead)		//打印链表
{
       LNode *pTemp = pListHead;
       while (pTemp) 
	   {
              printf("%d\t", pTemp->data);
              pTemp = pTemp->next;
       }
	   printf("\n");
}

LinkList Creat_LinkList2()		//在表尾插入的建立链式链表
{
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x;
	while(x!=-1)
	{
		printf("请按增序的输入加入链表的数字，输入-1结束\n");
		scanf("%d",&x);
		if (x!=-1)
		{
			s=(LNode*)malloc(sizeof(LNode));
			s->data=x;
			if(L==NULL)
				L=s;
			else
				r->next=s;
		    r=s;
		}
	}
	if(r!=NULL)
		r->next=NULL;
	return L;
}

LNode *Get_LinkList(LinkList L,int x)		//单链表中的查找
{
	LNode *q,*p=L;
	while(p->next!=NULL&&p->data<x)
	{
		q=p;
		p=p->next;
	}
	return q;
}

int Insert_LinkList(LinkList L,int x)		//单链表中的插入
{
	LNode *p,*s;
	p=Get_LinkList(L,x);
	s=(LNode*)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}


int main()
{
	LinkList L=NULL;
	int x;
	LinkList Creat_LinkList2();
	LNode *Get_LinkList(LinkList L,int x);
	int Insert_LinkList(LinkList L,int x);
	void print_list(LNode *pListHead);
	L=Creat_LinkList2();
	print_list(L);
	printf("请输入想要插入的数字，系统将会为您自动按增序插入\n");
	scanf("%d",&x);
	Insert_LinkList(L,x);
	print_list(L);
	return 0;
}