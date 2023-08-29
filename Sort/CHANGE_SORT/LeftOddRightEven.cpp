#include <stdio.h>
#include <stdlib.h>

void LR(int A[], int len)
{
    int left = 0;
    int right = len - 1;
    int tmp = A[right];
    while (left < right)
    {
        while (left < right && A[left] % 2 == 1)
        {
            left++;
        }
        A[right] = A[left];
        while (left < right && A[right] % 2 == 0)
        {
            right--;
        }
        A[left] = A[right];
    }
    A[left] = tmp;
}

int main()
{
    int a[] = {3, 2, 4, 7, 5};
    int len = sizeof(a) / sizeof(a[0]);
    LR(a, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}