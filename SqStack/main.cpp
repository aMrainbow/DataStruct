#include "function.h"

float FunOfEnd(char *arr)
{
    float a[] = {0, 0, 0, 0};
    int Label = -1;
    float res, tmp, tmp1, tmp2;
    while (*arr != '\0')
    {
        if (*arr >= '0' && *arr <= '9')
        {
            a[++Label] = (float)(*arr - '0');
            arr++;
        }
        else
        {
            if (*arr == '/')
            {
                tmp1 = a[Label--];
                tmp2 = a[Label--];
                tmp = tmp2 / tmp1;
                a[++Label] = tmp;
                arr++;
            }
            else if (*arr == '-')
            {
                tmp1 = a[Label--];
                tmp2 = a[Label--];
                tmp = tmp2 - tmp1;
                a[++Label] = tmp;
                arr++;
            }
            else if (*arr == '+')
            {
                tmp1 = a[Label--];
                tmp2 = a[Label--];
                tmp = tmp2 + tmp1;
                a[++Label] = tmp;
                arr++;
            }
            else
            {
                tmp1 = a[Label--];
                tmp2 = a[Label--];
                tmp = tmp2 * tmp1;
                a[++Label] = tmp;
                arr++;
            }
        }
    }
    res = a[0];
    return res;
}

bool Judge(char *arr)
{
    SqStack s;
    InitStack(s);
    char x;
    while (*arr != '\0')
    {
        if (*arr == '(' || *arr == '[' || *arr == '{')
        {
            Push(s, *arr);
            arr++;
        }
        else
        {
            if (GetPop(s) == '(' && *arr != ')')
            {
                return false;
            }
            if (GetPop(s) == '[' && *arr != ']')
            {
                return false;
            }
            if (GetPop(s) == '{' && *arr != '}')
            {
                return false;
            }
            Pop(s, x);
            arr++;
        }
    }
    return true;
}

void ShowCharArr(char *s)
{
    while (*s != '\0')
    {
        printf("%c ", *s++);
    }
}

void ShowCharArr2(char &s)
{
    while (s != '\0')
    {
        printf("%c ", s++);
    }
}

// Wangdao P82.3 用两个栈模拟一个队列
int EnQueue(SqStack &S1, SqStack &S2, Elemtype e)
{
    if (!StackOverFlow(S1))
    {
        Push(S1, e);
        return 1;
    }
    if (StackOverFlow(S1) && !StackEmpty(S2))
    {
        printf("队列已满。");
        return 0;
    }
    if (StackOverFlow(S1) && StackEmpty(S2))
    {
        Elemtype x;
        while (!StackEmpty(S1))
        {
            Pop(S1, x);
            Push(S2, x);
        }
    }
    Push(S1, e);
    return 1;
}

void DeQueue(SqStack &S1, SqStack &S2, Elemtype &e)
{
    if (!StackEmpty(S2))
    {
        Pop(S2, e);
    }
    else if (StackEmpty(S1))
    {
        printf("队列为空");
    }
    else
    {
        while (!StackEmpty(S1))
        {
            Pop(S1, e);
            Push(S2, e);
        }
        Pop(S2, e);
    }
}

void Train_Arrange(char *trian)
{
    char c, *p = trian, *q = trian;
    SqStack s;
    InitStack(s);
    while (*p != '\0')
    {
        if (*p == 'H')
        {
            Push(s, *p);
        }
        else
            *(q++) = *p;
        p++;
    }
    while (!StackEmpty(s))
    {
        Pop(s, c);
        *(q++) = c;
    }
}

// Wangdao P92.3
int P_n_x(int x, int n)
{
    int P[] = {1};
    P[1] = 2 * x;
    for (int i = 2; i <= n; i++)
    {
        P[i] = 2 * x * P[i - 1] - 2 * (n - 1) * P[i - 2];
    }
    return P[n];
}

int UseStack(int n, int x)
{
    typedef struct stack
    {
        int no;
        int val;
    } PStack;
    PStack P[10];
    int top = -1, i;
    int val1 = 1, val2 = 2 * x;
    for (i = n; i >= 2; i--)
    {
        top++;
        P[top].no = i;
    }
    while (top >= 0)
    {
        P[top].val = 2 * x * val2 - 2 * (P[top].no - 1) * val1;
        val1 = val2;
        val2 = P[top].val;
        top--;
    }
    if (n == 0)
    {
        return val1;
    }
    return val2;
}

int main()
{
    char train[] = {'H', 'S', 'H', 'H', 'S', '\0'};
    Train_Arrange(train);
    char *head = train;
    while (*head)
    {
        printf("%c", *head);
        head++;
    }
    // printf("%d", UseStack(2, 1));
    /*char test1[] = {'9', '2', '-', '5', '/', '\0'};
    char test2[] = {'(', '[', ']', ')', '\0'};
    char test3[] = {'(', '[', '(', '}', ']', ')', '\0'};
    if (Judge(test3) == true)
    {
        printf("true");
    }
    else
    {
        printf("flase");
    }*/
    // printf("test1的结果为 %f", FunOfEnd(test1));
    //  ShowCharArr(test1);
    //   printf("\n");
    //   ShowCharArr2(*test1);
    //   SqStack S1;
    //   InitStack(S1);
    return 0;
}