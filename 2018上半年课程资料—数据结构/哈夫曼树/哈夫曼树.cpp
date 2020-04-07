#include <stdio.h>  
#include<stdlib.h>  
#include<string.h>
const int MAXBIT = 100;  
const int MAXVALUE = 10000;  
const int MAXLEAF = 30;  
const int MAXNODE = MAXLEAF*2 -1;  
typedef struct  
{  
    int bit[MAXBIT];  
    int start;  
}HCodeType; 
typedef struct  
{  
    int weight;  
    int parent;  
    int lchild;  
    int rchild;  
    char value;  
}HNodeType;
void node_input(HNodeType HuffNode[], const int &n)  
{  
    int i;  
    for(i=0; i<n; i++)  
    {  
        printf ("Please input weight of leaf node %d: \n", i);  
        scanf ("%d %c", &HuffNode[i].weight,&HuffNode[i].value);
        HuffNode[i].parent =-1;  
        HuffNode[i].lchild =-1;  
        HuffNode[i].rchild =-1;
    }  
}  
void out_put(HNodeType HuffNode[],HCodeType HuffCode[], const int &n)  
{  
    int i, j;  
    for (i=0; i<n; i++)  
    {  
        printf ("%c 's Huffman code is: ",HuffNode[i].value);  
        for (j=HuffCode[i].start+1; j < n; j++)  
        {  
            printf ("%d", HuffCode[i].bit[j]);  
        }  
        printf(" start:%d",HuffCode[i].start);  
        printf ("\n");  
    }  
}  
void min_two(HNodeType HuffNode[],  const int &n,const int &i, int &x1, int &x2)  
{  
    int j, m1, m2;  
    m1=m2=MAXVALUE;  
    for (j=0; j<n+i; j++)  
    {  
        if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)  
        {  
            m2=m1;  
            x2=x1;  
            m1=HuffNode[j].weight;  
            x1=j;  
        }  
        else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)  
        {  
            m2=HuffNode[j].weight;  
            x2=j;  
        }  
    }  
}
void HuffmanTree(HNodeType HuffNode[],  const int &n)  
{
    int i, x1, x2;  
    for (i=0; i<n-1; i++)  
    {  
        x1=x2=0;  
        min_two(HuffNode, n, i, x1, x2);
        HuffNode[x1].parent  = n+i;  
        HuffNode[x2].parent  = n+i;  
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;  
        HuffNode[n+i].lchild = x1;  
        HuffNode[n+i].rchild = x2;  
        HuffNode[n+i].parent = -1;
        printf ("x1.weight and x2.weight in round %d: %d, %d\n", i+1, HuffNode[x1].weight, HuffNode[x2].weight);  /* ÓÃÓÚ²âÊÔ */  
        printf ("\n");  
    }
} 
void encodeing(HNodeType HuffNode[], HCodeType HuffCode[], const int &n)  
{  
    int i, j, c, p;  
    HCodeType cd;  
    for (i=0; i < n; i++)  
    {  
        cd.start = n-1;  
        c = i;  
        p = HuffNode[c].parent;  
        while (p != -1)   
        {  
            if (HuffNode[p].lchild == c)  
                cd.bit[cd.start] = 0;  
            else  
                cd.bit[cd.start] = 1;  
            cd.start--;
            c=p;  
            p=HuffNode[c].parent;  
        } 
        for (j=cd.start+1; j<n; j++)  
        {  
             HuffCode[i].bit[j] = cd.bit[j];  
        }  
        HuffCode[i].start = cd.start;  
    }  
}  
void decodeing(char string[],HNodeType Buf[],int Num)  
{  
      int i,tmp=0,code[1024];  
      int m=2*Num-1;  
      char *nump;  
      char num[1024];  
      for(i=0;i<strlen(string);i++)  
      {  
          if(string[i]=='0')  
            num[i]=0;  
          else if(string[i] == '1')  
            num[i]=1;  
          else  
             return;  
      }
      i=0;  
      nump=&num[0];  
      while(nump<(&num[strlen(string)]))  
      {  
        tmp=m-1;  
        while((Buf[tmp].lchild!=-1)&&(Buf[tmp].rchild!=-1))  
        {  
           if(*nump==0)  
           {  
                tmp=Buf[tmp].lchild ;  
           }  
           else   
                tmp=Buf[tmp].rchild;  
           nump++;  
        }  
          printf("%c",Buf[tmp].value);  
     }  
}  
  
int main(void)  
{  
    HNodeType HuffNode[MAXNODE];    
    HCodeType HuffCode[MAXLEAF],  cd; 
    int i, j, n;  
    char pp[100];  
    printf ("Please input n:\n");  
    scanf ("%d", &n);  
    node_input(HuffNode, n);  
    HuffmanTree(HuffNode, n);  
    encodeing(HuffNode,HuffCode,n);   
    out_put(HuffNode,HuffCode,n);  
    printf("Decoding?Please Enter code:\n");  
    scanf("%s",&pp);  
    decodeing(pp,HuffNode,n);  
    printf("\n"); 
    system("pause"); 
    return 0;  
} 

