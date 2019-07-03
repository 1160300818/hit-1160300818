#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define SIZE 20
#define LISTINCREMENT 10
typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data[SIZE];
    int length;
}SqList;
//初始化线性表
Status InitList(SqList *L)
{
    L->length=0;
    return OK;
}
//输出L中的每一个元素
Status ListTraverse(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    visit(L.data[i]);
    printf("\n");
    return OK;
}
//打印元素
Status visit(ElemType a)
{
    printf("%d\t",a);
    return OK;
}
//在L中第i个位置之前插入元素e
Status ListInsert(SqList *L,int i,ElemType e)
{
    int j;
    if(i<1||i>L->length+1)
    return ERROR;
    for(j=L->length;j>=i;j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[j]=e;
    L->length++;
    return OK;
}
//返回顺序表中的第i个元素
Status GetElem(SqList L,int i)
{
    return L.data[i-1];
}
//在顺序表中删除第i个元素
Status ListDelete(SqList *L,int i)
{
    if(i<1||i>L->length)
    return ERROR;
    for(int j=i;j<=L->length;j++)
    {
        L->data[j-1]=L->data[j];
    }
    L->length--;
    return OK;
}
Status LocateElem(SqList *L,ElemType e)
{
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]==e)
        return i+1;
    }
}
//返回指定元素的后继元素
Status NextElem(SqList *L,ElemType e)
{
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]==e)
        return L->data[i+1];
    }
}
int main()
{
    SqList L;
    ElemType e;
    Status i;
    i=InitList(&L);
    int j,k;
    int p;
    i=ListInsert(&L,1,2);
    ListTraverse(L);
    i=ListInsert(&L,2,3);
    ListTraverse(L);
    i=ListInsert(&L,1,4);
    ListTraverse(L);
    i=ListInsert(&L,2,5);
    ListTraverse(L);
    i=ListInsert(&L,1,6);
    ListTraverse(L);i=ListInsert(&L,6,9);
    ListTraverse(L);
    int value=GetElem(L,1);
    printf("第一个元素为:%d\n",value);
    printf("L中删除4后,顺序表为:");
    ListDelete(&L,2);
    ListTraverse(L);
    int locate=LocateElem(&L,3);
    printf("3的位置为:%d\n",locate);
    printf("3的下一个元素为:%d\n",NextElem(&L,3));
    printf("最后一个元素为:%d\n",GetElem(L,L.length));
    printf("删除L中最后一个元素后,顺序表为:");
    ListDelete(&L,L.length);
    ListTraverse(L);
    printf("删除L中第一个元素后,顺序表为:");
    ListDelete(&L,1);
    ListTraverse(L);
    printf("第二个元素为:%d\n",GetElem(L,2));

}

