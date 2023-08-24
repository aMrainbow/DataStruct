#include "function.h"

void InitShareStack(ShareStack &S)
{
    S.top[0] = -1;
    S.top[1] = maxsize;
}

int PushShareStack(int i, elemtp x)
{
    if (i > 1 || i < 0)
    {
        printf("栈号输入错误");
        exit(0);
    }
    if (s.top[1] - s.top[0] == 1)
    {
        printf("栈已满");
        return 0;
    }
    switch (i)
    {
    case 0:
        s.stack[++s.top[0]] = x;
        return 1;
        break;
    case 1:
        s.stack[--s.top[1]] = x;
        return 1;
        break;
    }
    return 1;
}

elemtp PopShareStack(int i)
{
    elemtp tmp = 0;
    if (i > 1 || i < 0)
    {
        printf("栈号输入错误");
        exit(0);
    }
    switch (i)
    {
    case 0:
        if (s.top[0] == -1)
        {
            printf("栈为空");
            return -1;
        }
        else
            tmp = s.stack[s.top[0]--];
        break;
    case 1:
        if (s.top[1] == maxsize)
        {
            printf("栈为空");
            return -1;
        }
        else
            tmp = s.stack[s.top[1]++];
        break;
    }
    return tmp;
}

elemtp GetTopShareStack(int i, ShareStack S)
{
    elemtp tmp = 0;
    if (i > 1 || i < 0)
    {
        printf("栈号输入错误");
        exit(0);
    }
    switch (i)
    {
    case 0:
        if (s.top[0] == -1)
        {
            printf("栈为空");
            return -1;
        }
        else
            tmp = s.stack[s.top[0]];
        break;
    case 1:
        if (s.top[1] == maxsize)
        {
            printf("栈为空");
            return -1;
        }
        else
            tmp = s.stack[s.top[1]];
        break;
    }
    return tmp;
}