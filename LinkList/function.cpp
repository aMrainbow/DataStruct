#include "function.h"

// 头插法
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 尾插法
LinkList List_TailInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *r = L;
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 用尾插法创建不带头节点的单链表
LinkList No_HeadList_TailInsert(LinkList &L)
{
    int x;
    LNode *r;
    LNode *s;
    r = L;
    printf("请输入数据： ");
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        if (L == NULL)
        {
            L = s;
            r = L;
        }
        else
        {
            r->next = s;
            r = s;
        }
        scanf("%d", &x);
    }
    return L;
}

// 按序号查找节点
LNode *GetElem(LinkList L, int i)
{
    if (i < 1)
    {
        return NULL;
    }
    int j = 1;
    LNode *p = L->next;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找节点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 在p节点后插入元素
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertElem(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p, *s;
    p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}

void ShowLinkList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void ShowNoHeadList(LinkList L)
{
    LNode *p = L;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int GetLen(LinkList L)
{
    LNode *p = L->next;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}