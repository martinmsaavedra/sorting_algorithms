#include "sort.h"

void merge_sort(int *array, size_t size)
{

    if ((!array) || size < 2)
        return;

    mergeSort(array, 0, (size - 1));
}

void mergeSort(int *array, size_t left, size_t right)
{
    size_t mid;

    if (left < right)
    {
        mid = left + (right - left) / 2;
        printf("MID %lu\n", mid);
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void merge(int *array, size_t left, size_t mid, size_t right)
{
    size_t n1 = 0, n2 = 0;

    (void)array;
    printf("L = %lu\n", left);
    printf("MID %lu\n", mid);
    printf("R = %lu\n", right);
    n1 = mid - (right + 1);
    n2 = left - mid;
    printf("Merging...\n");
    printf("n1 %lu\n", n1);
    printf("n2 %lu\n", n2);
    return;
}
