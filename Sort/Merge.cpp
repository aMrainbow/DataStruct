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

int main()
{
    int A[] = {3, 6, 2, 9, 4, 1};
    MergeSort(A, 0, 5);
    for (int i = 0; i <= 5; i++)
    {
        printf("%d ", A[i]);
    }
}