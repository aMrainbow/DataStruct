#include <iostream>
#include <string>
using namespace std;

void shellSort(int a[], int len)
{
    int d = len; // gap的值
    while (true)
    {
        d = d / 2; // 每次都将gap的值减半
        for (int x = 0; x < d; x++)
        { // 对于gap所分的每一个组
            for (int i = x + d; i < len; i = i + d)
            { // 进行插入排序
                int temp = a[i];
                int j;
                for (j = i - d; j >= 0 && a[j] > temp; j = j - d)
                {
                    a[j + d] = a[j];
                }
                a[j + d] = temp;
            }
        }
        if (d == 1)
        { // gap==1，跳出循环
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = {4, 7, 6, 5, 9, 12};
    int len = sizeof(a) / sizeof(a[0]);
    shellSort(a, len);
}