#include "sort.h" 
/**
 * radix_sort -
 * @array: The array
 * @size: The size of the array
 * Return: Nothing
 */
int LSD(int *array, size_t size)
{
    size_t i = 0;
    int lsd = 0;
    if (array != NULL)
    {
        lsd = array[0];
        for (; i < size; i++)
        {
            if (lsd > array[i])
                lsd = array[i];
        }
        return (lsd);
    }
    else
        return (0);
}

int largest_int(int *array, size_t size)
{
    size_t i = 0;
    int largest = array[0];
    for (; i < size; i++)
    {
        if (largest < array[i + 1] && i + 1 < size)
            largest = array[i + 1];
    }
    return (largest);
}

int is_in(int *array, size_t size, int num)
{
    size_t i = 0;
    int count = 0;
    for (; i < size; i++)
    {
        if (num == array[i])
            count++;
    }
    return (count);
}

void radix_sort(int *array, size_t size)
{
    int *radix = NULL, lsd = 0, largest = 0, large_arr = 0;
    int i = 0, j = 0, k = 0;
    int count = 0;
    lsd = LSD(array, size);
    largest = largest_int(array, size);
    large_arr = largest - lsd;
    if (array != NULL && size > 1)
    {
        radix = malloc(sizeof(int) * large_arr + 1);
        for (j = lsd; j < largest + 1; j++)
        {
            count = is_in(array, size, j);
            radix[j - lsd] = count;
        }
        for (j = 0; j < large_arr + 1; j++)
        {
            if (radix[j] != 0)
            {
                for (k = radix[j]; k > 0; k--)
                    array[i++] = j + lsd;
                /*printf("%d ->  %d\n", radix[j], j + lsd);*/
            }
        }
        free(radix);
    }
    print_array(array, size);
}
