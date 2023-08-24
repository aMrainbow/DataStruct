#ifndef __FUNCTION_H
#define __FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

#define maxsize 50
#define elemtp int

typedef struct
{
    elemtp stack[maxsize];
    int top[2];
} ShareStack;
extern ShareStack s;

void InitShareStack(ShareStack &s);
int PushShareStack(int i, elemtp x);
elemtp PopShareStack(int i);
elemtp GetTopShareStack(int i, ShareStack S);

#endif