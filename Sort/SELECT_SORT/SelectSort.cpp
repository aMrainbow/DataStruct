#include <stdio.h>
#include <stdlib.h>

void SelectSort(int A[], int len)
{
    int tmp = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }
    }
}

int main()
{
    int a[] = {4, 7, 6, 5, 9, 12};
    int len = sizeof(a) / sizeof(a[0]);
    SelectSort(a, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}