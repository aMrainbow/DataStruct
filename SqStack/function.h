#ifndef __FUNCTION_H
#define __FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

#define Elemtype char
#define Maxsize 50
typedef struct
{
    Elemtype data[Maxsize];
    int top;
} SqStack;

void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack &S, Elemtype x);
bool Pop(SqStack &S, Elemtype &x);
Elemtype GetPop(SqStack &S);
bool StackOverFlow(SqStack S);

#endif