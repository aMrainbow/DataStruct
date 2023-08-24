#ifndef __FUNCTION_H
#define __FUNCTION_H
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
    /* data */
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L);
LinkList List_TailInsert(LinkList &L);
LinkList No_HeadList_TailInsert(LinkList &L);
LNode *GetElem(LinkList L, int i);
LNode *LocateElem(LinkList L, int e);
bool InsertNextNode(LNode *p, int e);
bool InsertElem(LinkList &L, int i, int e);
void ShowLinkList(LinkList L);
void ShowNoHeadList(LinkList L);
int GetLen(LinkList L);

#endif