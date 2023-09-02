#include <stdio.h>
#include <stdlib.h>

int *B = (int *)malloc(sizeof(int));
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
    {
        B[k] = A[k];
    }
    for (i = low, j = mid + 1, k = i; i < mid + 1 && j <= high; k++)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = B[j++];
        }
    }
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

void MergeMN(int A[], int m, int n)
{
    for (int index = 0; index <= m + n; index++)
    {
        B[index] = A[index];
    }
    int i = 1, j = m + 1;
    int k;
    for (i, j, k = i; i <= m && j <= m + n; k++)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = B[j++];
        }
    }
    while (i <= m)
    {
        A[k++] = B[i++];
    }
    while (j <= m + n)
    {
        A[k++] = B[j++];
    }
}

void CountSort(int A[], int len)
{
    int c = 0, tmp;
    for (int i = 0; i < len; i++)
    {
        tmp = A[i];
        for (int j = 0; j < len; j++)
        {
            if (A[j] < tmp)
            {
                c++;
            }
        }
        B[c] = tmp;
        c = 0;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", B[i]);
    }
}

int main()
{
    int A[] = {3, 6, 2, 9, 4, 1};
    /*MergeSort(A, 0, 5);
    int C[] = {0, 1, 3, 5, 7, 2, 4, 6};
    MergeMN(C, 4, 3);
    for (int i = 1; i <= 7; i++)
    {
        printf("%d ", C[i]);
    }*/
    int len = sizeof(A) / sizeof(A[0]);
    CountSort(A, len);
}