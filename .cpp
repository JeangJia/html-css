#include <stdio.h>
#include <stdlib.h>
void quicksort(int *a, int begin, int end)
{
    if (begin >= end)
        return;
    int left = begin, right = end;
    int pivot = a[left];
    while (left < right)
    {
        while (left < right && a[right] > pivot)
            right--;
        if (left < right)
        {
            a[left] = a[right];
            left++;
        }
        while (left < right && a[left] < pivot)
            left++;
        if (left < right)
        {
            a[right] = a[left];
            right--;
        }
    }
    a[left] = pivot;
    quicksort(a, begin, left - 1);
    quicksort(a, left + 1, end);
}
int main()
{
    int a[] = {23, 34, 2, 5, 2, 67, 1};
    int n = sizeof(a) / sizeof(a[0]);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}