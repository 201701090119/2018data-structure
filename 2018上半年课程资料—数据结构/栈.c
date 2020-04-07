
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define StackSize 50
typedef struct
{
 char data[StackSize];
 int top;
}SeqStack;
//�ж�ջ�Ƿ�Ϊ��
int IsEmpty(SeqStack *s)
{
 return(s->top==-1?TRUE:FALSE);
}
// ��ջ
int Push(SeqStack *s,char x)
{
 if(s->top==StackSize-1)return(FALSE);
 s->top++;
 s->data[s->top]=x;
 return(TRUE);
}
// ȡջ��Ԫ��
int Pop(SeqStack *s,char *x)
{
 if(s->top==-1)
  return(FALSE);
 else
 {
  *x=s->data[s->top];
  s->top--;
  return(TRUE);
 }
}

//�����ж�
int IsSame()
{ char ch,m,str[50];
 int i=0,j=0;
 SeqStack *p;
 p = (SeqStack *)malloc(sizeof(SeqStack));
 p->top = -1;
 while((ch=getchar())!='\n')
 {
  Push(p,ch);str[i]=ch;i++;
  printf("%d\n",i);
 }
 
 while(!IsEmpty(p))
 {
  Pop(p,&m);
  if(m!=str[j++])
   return FALSE;
 }
 return TRUE;
}

void main()
{ int temp;
 printf("\t�����ж�\n");
 printf("�����ַ�����\n");
 temp=IsSame();
 if(temp)
  printf("yes!\n");
 else printf("no\n");
}
