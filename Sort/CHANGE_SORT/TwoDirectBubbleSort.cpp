#include <stdio.h>
#include <stdlib.h>

void TwoDirBubbleSort(int A[], int len)
{
    int change = 1;
    int i = len - 1;
    int tmp = 0;
    while (i > 0)
    {
        if (change % 2 == 1)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if (A[j] > A[j + 1])
                {
                    tmp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = tmp;
                }
            }
        }
        else
        {
            for (int j = i; j > 0; j--)
            {
                if (A[j] < A[j - 1])
                {
                    tmp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;
                }
            }
        }
        i--;
        change++;
    }
}

int main()
{
    int a[] = {4, 7, 6, 5, 9, 12};
    int len = sizeof(a) / sizeof(a[0]);
    TwoDirBubbleSort(a, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}