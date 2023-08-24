#include "function.h"

// 王道链表综合题第一题
void DelteSameValue(LinkList &L, int x)
{
    LNode *p = L;
    if (L == NULL)
    {
        return;
    }
    if (p->data == x)
    {
        L = L->next;
        free(p);
        DelteSameValue(L, x);
    }
    else
    {
        DelteSameValue(L->next, x);
    }
}

// 有头结点的单链表中删除全部值为x的结点
void DeleteSameValue(LinkList L, int x)
{
    LNode *pre = L;
    LNode *p = L->next, *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

// 递归的删除带头节点的单链表中全部值为x的结点
void RecursionDeleteValue(LinkList L, int x)
{
    LNode *p = L->next;
    // LNode *pre = L;
    if (p == NULL)
    {
        return;
    }
    if (p->data == x)
    {
        L->next = p->next;
        RecursionDeleteValue(L, x);
    }
    else
    {
        RecursionDeleteValue(L->next, x);
    }
}

// My WangDao 2.3,2.5
void TailToHeadOut(LinkList L)
{
    int len = GetLen(L);
    int num = len;
    printf("这个链表长%d\n ", GetLen(L));

    while (num - 1 > 0)
    {
        LNode *p = L->next;
        LNode *later = p->next;
        for (int i = num - 1; i > 0; i--)
        {
            int tmp = 0;
            tmp = p->data;
            p->data = later->data;
            later->data = tmp;
            p = p->next;
            later = later->next;
        }
        num--;
    }
    ShowLinkList(L);
}

// WanGDao's 2.3
void R_Print(LinkList L)
{
    if (L->next != NULL)
    {
        R_Print(L->next);
    }
    if (L != NULL)
        printf("%d ", L->data);
}
void R_Ignore_Head(LinkList L)
{
    if (L->next != NULL)
        R_Print(L->next);
}

// WangDao's 2.5
LinkList Reverse(LinkList L)
{
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

// My WangDao 2.6
void LinkListSort(LinkList L)
{
    int len = GetLen(L);
    int num = len;
    while (num - 1 > 0)
    {
        LNode *p = L->next;
        LNode *later = p->next;
        for (int i = num - 1; i > 0; i--)
        {
            if (p->data > later->data)
            {
                int tmp = 0;
                tmp = p->data;
                p->data = later->data;
                later->data = tmp;
                p = p->next;
                later = later->next;
            }
            else
            {
                p = p->next;
                later = later->next;
            }
        }
        num--;
    }
    ShowLinkList(L);
}

// MY WangDao 2.7
void DeleteRangeNum(LinkList L, int h, int t)
{
    LinkListSort(L);
    LNode *p = L->next, *q;
    LNode *pre = L;
    while (p != NULL)
    {
        if (p->data >= h && p->data <= t)
        {
            q = p;
            pre->next = p->next;
            if (p->next != NULL)
            {
                p = p->next;
            }
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    printf("删除后：");
    ShowLinkList(L);
}

int main()
{
    LinkList L = NULL;
    List_TailInsert(L);
    // LinkListSort(L);
    DeleteRangeNum(L, 1, 3);
    return 0;
}