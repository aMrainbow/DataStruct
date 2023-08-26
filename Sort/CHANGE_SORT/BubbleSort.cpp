#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int A[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        bool flag = false;
        for (int j = len - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = true;
            }
        }
        if (flag == false)
        {
            return;
        }
    }
}

int main()
{
    int a[] = {4, 7, 6, 5, 9, 12};
    int len = sizeof(a) / sizeof(a[0]);
    BubbleSort(a, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}