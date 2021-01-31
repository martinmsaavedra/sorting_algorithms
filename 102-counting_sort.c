#include "sort.h"

void counting_sort(int *array, size_t size)
{
    size_t j = 0;
    int max = 0, i = 0, *count, counter, total = 0, l = 0;

    if (array == NULL || size < 2)
        return;
    
    for (i = 0; i < (int)size; i++)
    {
        if (max < array[i])
            max = array[i];
    }

    count = malloc(sizeof(int) * max + 1);
    if (count == NULL)
        return;
    
    for (i = 0; i < (int)size; i++)
        count[i] = 0;

    for (i = 0; i < max + 1; i++)
    {
        counter = 0;
        for (j = 0; j < size; j++)
        {
            if (i == (int)array[j])
            {
                counter++;
            }
        }
        count[i] = counter;
        total = total + counter;
        if (i != max)
            printf("%d, ", total);
        else
            printf("%d", total);
    }
    printf("\n");

    for (i = 0; i < max + 1; i++)
    {
        if (count[i] != 0)
        {
            for (j = 0; j < (size_t)count[i]; j++)
            {
                array[l] = i;
                l++;
            }
        }
    }

    free(count);
}