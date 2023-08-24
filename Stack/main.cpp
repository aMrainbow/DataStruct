#include "function.h"

ShareStack s;

int main()
{
    elemtp x = 1;
    InitShareStack(s);
    PushShareStack(0, x);
    printf("%d", GetTopShareStack(0, s));
}