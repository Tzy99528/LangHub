#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

Status CreateList(LinkList L, int n);
void PrintList(LinkList L);
Status GetElem(LinkList L, int i, ElemType *e);
Status InsertList(LinkList L, int i, ElemType e);
Status DeleteList(LinkList L, int i, ElemType *e);
int Locate(LinkList L, Elemtype e, (*compare)(ElemType, ElemType));
int equal(ElemType x, ElemType y);

int main()
{
    return 0;
}

Status CreateList(LinkList L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList p = L;
    for (int i = 0; i < n; i++)
    {
        LinkList q = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &q->data);
        q->next = NULL:
        p->next = q;
        p = p->next;
    }
    return OK;
}

void PrintList(LinkList L)
{
    LinkList p = L->next;
    while(!p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p = L->next;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    *e = p->data;
    return OK;
}

Status InsertList(LinkList L, int i, ElemType e)
{
    LinkList p = L;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status DeleteList(LinkList L, int i, ElemType *e)
{
    LinkList p = L;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    q = p->next;
    p-next = q->next;
    free(q);
    return OK;
}

int Locate(LinkList L, Elemtype e, (*compare)(ElemType, ElemType))
{
    int i = 1;
    LinkList p = L->next;
    while ((*compare)(p->data, e))
    {
        p = p->next;
        i++;
    }
    if (!p)
        return i;
    else
        return -1;
}

int equal(ElemType x, ElemType y)
{
    if (x == y)
        return 1;
    else
        return 0;
}