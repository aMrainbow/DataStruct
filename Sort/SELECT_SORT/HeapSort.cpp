#include <stdio.h>
#include <stdlib.h>

void HeapAdjust(int A[], int k, int len)
{
    // 此函数将元素k为根的子树进行调整
    A[0] = A[k]; // A[0]暂存子树根节点
    for (int i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && A[i] < A[i + 1])
        {
            i++;
        }
        if (A[0] >= A[i])
        {
            break;
        }
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        HeapAdjust(A, i, len);
    }
}

void HeapSort(int A[], int len)
{
    int tmp = 0;
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--)
    {
        tmp = A[i];
        A[i] = A[1];
        A[1] = tmp;
        HeapAdjust(A, 1, i - 1);
    }
}

void JudgeHeap(int A[], int len)
{
    if (len % 2 == 0)
    {
        if (A[len / 2] > A[len])
        {
            printf("Not a Small Head Heap.");
        }
        for (int i = len / 2; i > 0; i--)
        {
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
            {
                printf("Not a Small Head Heap.");
                break;
            }
        }
    }
    else
    {
        for (int i = len / 2; i > 0; i--)
        {
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
            {
                printf("Not a Small Head Heap.");
                break;
            }
        }
    }
    printf("It is a Small Head Heap.");
}

int main()
{
    int a[] = {NULL, 4, 7, 6, 5, 9, 12};
    int len = sizeof(a) / sizeof(a[0]);
    HeapSort(a, len);
    for (int i = 2; i <= len; i++)
    {
        printf("%d ", a[i]);
    }
    JudgeHeap(a, len);
}