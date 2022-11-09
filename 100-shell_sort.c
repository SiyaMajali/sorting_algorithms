#include "sort.h"

int check_ordered(int *array, size_t size);

void shell_sort(int *array, size_t size)
{
	size_t i, j, knuth = 1;
	int temp;

	if (!array || size <= 1 || (check_ordered(array, size) == 1))
		return;
	while (((knuth * 3) + 1) < size)
		knuth = (knuth * 3) + 1;
	while (check_ordered(array, size) == 0)
	{
		for (i = 0, j = i + knuth; i < j && j != size; i++, j++)
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		if (knuth > 1)
		{
			print_array(array, size);
			knuth = (knuth / 3);
		}
	}
	print_array(array, size);
}

int check_ordered(int *array, size_t size)
{
	size_t i, ordered = 0;

	for (i = 0; i < (size - 1); i++)
	{
		if (array[i] <= array[i + 1])
			ordered = 1;
		else
			return (0);
	}
	return (ordered);
}
