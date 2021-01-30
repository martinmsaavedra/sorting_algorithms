#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t h = 1, i, n;
	int number;

	if (array == NULL || size < 2)
			return;

    while (h < size / 3) {
        h = 3 * h + 1;
    }

    while (h > 0) {
        for (i = h; i < size; i += h) {
            for (n = i; n > 0 && array[n] < array[n-h]; n -= h) 
			{
                number = array[n];
                array[n] = array[n-h];
                array[n-h] = number;
				
            }
        }
        h = h - 1;
		h = h / 3;
		print_array(array, size);
    }
}
