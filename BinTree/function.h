#ifndef __FUNCTION_H
#define __FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ElemType BinTree
#define MaxSize 50

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

typedef struct
{
    ElemType data[MaxSize];
    int top;
} Stack;

typedef struct QNode *PtrToQNode;
struct QNode
{
    ElemType *Data;
    int Front, Rear;
    int Max = MaxSize;
};
typedef PtrToQNode Queue;

#endif