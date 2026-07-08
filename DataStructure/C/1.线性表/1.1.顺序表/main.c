#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INITSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *data;
    int length;
    int maxsize;
} SqList;

Status InitList_Sq(SqList *L);
Status CreateList_Sq(SqList *L, int n);
void PrintList_Sq(SqList L);
Status ListInsert_Sq(SqList *L, int i, ElemType e);
Status ListDelete_Sq(SqList *L, int i, ElemType *e);
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
Status equal(ElemType x, ElemType y);

int main()
{
    SqList L;
    InitList_Sq(&L);
    int n;
    scanf("%d", &n);
    CreateList_Sq(&L, n);
    PrintList_Sq(L);
    ListInsert_Sq(&L, 1, 90);
    ElemType *x;
    ListDelete_Sq(&L, 2, x);
    printf("%d\n", *x);
    int i = LocateElem_Sq(L, 1, equal);
    printf("%d\n", i);
    return 0;
}

Status InitList_Sq(SqList *L)
{
    L->data = (ElemType *)malloc(INITSIZE * sizeof(ElemType));
    if (!L->data)
    {
        printf("内存分配失败！\n");
        exit(OVERFLOW);
    }
    L->length = 0;
    L->maxsize = INITSIZE;
    return OK;
}

Status CreateList_Sq(SqList *L, int n)
{
    if (n >= L->maxsize)
        return ERROR;
    for (int i = 0; i < n; i++)
        scanf("%d", &L->data[i]);
    L->length = n;
    return OK;
}

void PrintList_Sq(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// i范围为 1～n+1
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
    if (i > L->length + 1 || i < 1)  return ERROR;
    if (L->length + 1 > L->maxsize)
    {
        SqList *new, *p;
        new->data = (ElemType*)malloc((L->length + 1) * sizeof(ElemType));
        if (!new->data)
        {
            printf("内存分配失败\n");
            exit(OVERFLOW);
        }
        for (int j = 0; j < L->length; j++)
            new->data[j] = L->data[j];
        new->length = L->length;
        new->maxsize = L->maxsize;
        p = L;
        L = new;
        free(p);
    }
    for (int j = L->length - 1; j >= i - 1; j--)
    {
        L->data[j + 1] = L->data[j];
    }
    L->data[i] = e;
    L->length++;
    return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e)
{
    *e = L->data[i - 1];
    for (int j = i - 1; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return OK;
}

int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 1;
    while (i <= L.length && !(*compare)(e, L.data[i - 1]))
        i++;
    if (i <= L.length)
        return i;
    else
        return 0;
}

Status equal(ElemType x, ElemType y)
{
    if (x == y)
        return OK;
    else
        return ERROR;
}