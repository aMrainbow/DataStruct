#include <stdio.h>
#include <stdlib.h>

int Partition(int A[], int low, int high)
{
    int random = rand() % high + low;
    int pivot = A[random];
    int tmp = 0;
    tmp = A[low];
    A[low] = pivot;
    A[random] = tmp;
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            high--;
        }
        A[low] = A[high];

        while (low < high && A[low] <= pivot)
        {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void RandomQuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(A, low, high);
        RandomQuickSort(A, low, pivotpos - 1);
        RandomQuickSort(A, pivotpos + 1, high);
    }
}

int main()
{
    int a[] = {4, 7, 6, 5, 12, 9};
    int len = sizeof(a) / sizeof(a[0]);
    RandomQuickSort(a, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}