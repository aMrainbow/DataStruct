#include <stdio.h>
#include <stdlib.h>

enum Color
{
    Red = 1,
    White,
    Bule
} color;

void HollandSort(int A[], int len)
{
    int tmp = 0, i = 0;
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        switch (A[left])
        {
        case Red:
            tmp = A[i];
            A[i] = A[left];
            A[left] = tmp;
            i++;
            left++;
            break;
        case White:
            left++;
            break;
        case Bule:
            tmp = A[right];
            A[right] = A[left];
            A[left] = tmp;
            right--;
            break;
        default:
            break;
        }
    }
}

int main()
{

    int a[] = {Bule, Red, White, Bule, White};
    int len = sizeof(a) / sizeof(a[0]);
    HollandSort(a, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}