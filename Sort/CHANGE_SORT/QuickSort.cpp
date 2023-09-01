#include <stdio.h>
#include <stdlib.h>

void swap(int &A, int &B)
{
    int tmp = A;
    A = B;
    B = tmp;
}

int Partition(int A[], int low, int high)
{
    int pivot = A[low]; // 当前表中第一个元素设为枢轴，对表进行划分
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

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

int main()
{
    int a[] = {7, 3, 5, 9, 12, 2};
    int len = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, len - 1);
    // swap(a[0], a[1]);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}