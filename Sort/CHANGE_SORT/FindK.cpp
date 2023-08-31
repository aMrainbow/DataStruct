#include <stdio.h>
#include <stdlib.h>

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

int FindK(int A[], int low, int high, int k)
{
    QuickSort(A, low, high);
    return A[k - 1];
}

int kth_elem(int a[], int low, int high, int k)
{
    int pivot = a[low];
    int low_temp = low;
    int high_temp = high;
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
        {
            high--;
        }
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
        {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivot;
    if (low == k)
    {
        return a[low];
    }
    else if (low > k)
    {
        return kth_elem(a, low_temp, low - 1, k);
    }
    else
    {
        return kth_elem(a, low + 1, high_temp, k);
    }
}

int main()
{
    int a[] = {0, 7, 3, 5, 9, 12, 2};
    int len = sizeof(a) / sizeof(a[0]);
    int kth = 5;
    int k = kth_elem(a, 1, len - 1, kth);
    printf("第%d小的数:%d", kth, k);
}