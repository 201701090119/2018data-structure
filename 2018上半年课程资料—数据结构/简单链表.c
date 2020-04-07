#include<stdio.h>
#include<malloc.h>
typedef struct lnode
{
	int data;
	struct lnode*next;
}LNode,*LinkList;

void print_list(LNode *pListHead)		//��ӡ����
{
       LNode *pTemp = pListHead;
       while (pTemp) 
	   {
              printf("%d\t", pTemp->data);
              pTemp = pTemp->next;
       }
	   printf("\n");
}

LinkList Creat_LinkList2()		//�ڱ�β����Ľ�����ʽ����
{
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x;
	while(x!=-1)
	{
		printf("�밴��������������������֣�����-1����\n");
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

LNode *Get_LinkList(LinkList L,int x)		//�������еĲ���
{
	LNode *q,*p=L;
	while(p->next!=NULL&&p->data<x)
	{
		q=p;
		p=p->next;
	}
	return q;
}

int Insert_LinkList(LinkList L,int x)		//�������еĲ���
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
	printf("��������Ҫ��������֣�ϵͳ����Ϊ���Զ����������\n");
	scanf("%d",&x);
	Insert_LinkList(L,x);
	print_list(L);
	return 0;
}