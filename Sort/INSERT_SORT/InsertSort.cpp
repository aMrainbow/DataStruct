#include <stdio.h>
#include <stdlib.h>

void InsertSort(int A[], int len)
{
    int i, j, tmp;
    for (i = 2; i <= len; i++)
    {
        if (A[i - 1] > A[i])
        {
            tmp = A[i]; // 只需要常数个辅助空间，空间复杂度为O(1)
            for (j = i - 1; A[j] > tmp; j--)
            {
                A[j + 1] = A[j];
            }
            A[j + 1] = tmp;
        }
    }
}

int main()
{
    int a[] = {0, 4, 7, 6, 5, 9, 12};
    int len = sizeof(a) / sizeof(a[0]);
    InsertSort(a, len);
    for (int i = 1; i <= len; i++)
    {
        printf("%d ", a[i]);
    }
}
