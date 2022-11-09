#include "sort.h"

void radix_sort(int *array, size_t size)
{
	int *new_array = malloc(sizeof(int) * size);
	int i, j, int_size = (int)size, exponent = 10;

	if (!array || !new_array || size < 2)
		return;

	while (sorted(array, size) != 0)
	{
		for (i = 0; i < int_size; i++)
			new_array[i] = (array[i] % exponent);

		selection_sort(new_array, size);
		for (i = 0, j = 0; i < int_size; i++)
			if ((array[i] % exponent) == (new_array[j]))
				if ((j == 0) || (array[i] != new_array[j - 1]))
					new_array[j] = array[i], i = -1, j++;
		
    for (i = 0; i < int_size; i++)
			array[i] = new_array[i];
		print_array(array, size), exponent *= 10;
	}
	free(new_array);
}

int sorted(int *array, size_t size)
{
	int i;

	for (i = 0; i < (int)size - 1; i++)
		if (array[i] > array[i + 1])
			return (1);

	return (0);
}

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, flag, minindex, temp;
	int minval;

	if (!array)
		return;

	for (i = 0, flag = 0, minval = array[i]; i < size; i++, minval = array[i])
	{
		for (j = i + 1; array[j]; j++)
			if (array[j] < minval)
				minval = array[j], minindex = j, flag = 1;
		if (flag == 1)
		{
			temp = array[i], array[i] = minval, array[minindex] = temp;
			flag = 0;
		}
	}
}
