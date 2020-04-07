#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define datatypebt char
#define MAXVALUE 10000
#define m 4//叶子结点个数为m
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}Hnodetype;
//Hnodetype HFMtree[2*m-1];
typedef struct
{
    int bit[m];//m为叶子结点个数
    int start;
}Hcodetype;
//Hcodetype HFMcode[m];
void Create_HuffMtree(Hnodetype HFMtree[],int n)
{
    int m1,x1,m2,x2;
    int i,j;
    for(i=0;i<2*n-1;i++)
    {
        HFMtree[i].weight=0;
        HFMtree[i].parent=-1;
        HFMtree[i].lchild=-1;
        HFMtree[i].rchild=-1;
    }
    for(i=0;i<n;i++)
    {
        printf("%c:  ",i+65);
        scanf("%d",&HFMtree[i].weight);
    }
    for(i=0;i<n-1;i++)
    {
        x1=x2=MAXVALUE;
        m1=m2=0;
        for(j=0;j<n+i;j++)
        {
            if(HFMtree[j].parent==-1&&HFMtree[j].weight<x1)
            {
                x2=x1;
                m2=m1;
                x1=HFMtree[j].weight;
                m1=j;
            }
            else if(HFMtree[j].parent==-1&&HFMtree[j].weight<x2)
            {
                x2=HFMtree[j].weight;
                m2=j;
            }
        }
        HFMtree[m1].parent=n+i;
        HFMtree[m2].parent=n+i;
        HFMtree[n+i].weight=HFMtree[m1].weight+HFMtree[m2].weight;
        HFMtree[n+i].lchild=m1;
        HFMtree[n+i].rchild=m2;
    }

}
void HaffmanCode(Hnodetype HFMtree[],Hcodetype HFMcode[],int n)
{
    Hcodetype cd;
    int i,j,c,p;
    for(i=0;i<n;i++)
    {
        memset(HFMcode[i].bit,0,sizeof(HFMcode[i].bit));
        cd.start=n-1;
        c=i;
        p=HFMtree[c].parent;
        while(p!=-1)
        {
            if(HFMtree[p].lchild==c)
                cd.bit[cd.start]=0;
            else
                cd.bit[cd.start]=1;
            cd.start--;
            c=p;
            p=HFMtree[c].parent;
        }
        for(j=cd.start+1;j<n;j++)
        {
            HFMcode[i].bit[j]=cd.bit[j];
        }
        HFMcode[i].start=cd.start+1;
    }
}
void putsHFMtree(Hnodetype HFMtree[])
{
    printf("    weight  lchild   rchild    parent\n");
    for(int i=0;i<2*m-1;i++)
    {
        printf("%c:  %4d",i+65,HFMtree[i].weight);
        if(HFMtree[i].lchild!=-1)
            printf("    %4c",HFMtree[i].lchild+65);
        else
            printf("    %4d",HFMtree[i].lchild);
        if(HFMtree[i].rchild!=-1)
            printf("     %4c",HFMtree[i].lchild+65);
        else
            printf("     %4d",HFMtree[i].lchild);
        if(HFMtree[i].parent!=-1)
            printf("      %4c\n",HFMtree[i].parent+65);
        else
            printf("      %4d\n",HFMtree[i].parent);
    }
}
void putsHFMcode(Hcodetype HFMcode[])
{
    printf("Huffcode        bit         start\n");
    for(int i=0;i<m;i++)
    {
        printf("  %2d\t      ",i);
        for(int j=0;j<m;j++)
        {
            printf("%d ",HFMcode[i].bit[j]);
        }
        printf("\t     %2d\n",HFMcode[i].start);
    }
}
int main()
{
    Hnodetype HFMtree[2*m-1];
    Hcodetype HFMcode[m];
    Create_HuffMtree(HFMtree,m);
    HaffmanCode(HFMtree,HFMcode,m);
    putsHFMtree(HFMtree);
    putsHFMcode(HFMcode);
    return 0;
}
