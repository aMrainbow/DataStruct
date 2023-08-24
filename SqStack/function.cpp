#include "function.h"

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
        return false;
}

bool StackOverFlow(SqStack S)
{
    if (S.top == Maxsize - 1)
    {
        return true;
    }
    else
        return false;
}

bool Push(SqStack &S, Elemtype x)
{
    if (S.top == Maxsize - 1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, Elemtype &x)
{
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

Elemtype GetPop(SqStack &S)
{
    Elemtype x;
    if (S.top == -1)
    {
        return 'F';
    }
    x = S.data[S.top];
    return x;
}
