#include "sort.h"

void quick_sort(int *array, size_t size)
{
	int i, ordered;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < ((int)size - 1); i++)
	{
		if (array[i] <= array[i + 1])
			ordered = 1;
		else
		{
			ordered = 0;
			break;
		}
	}
	if (ordered == 1)
		return;
	if (ordered == 0)
		sort(array, size, 0, (size - 1));
}

void sort(int *array, size_t size, int start, size_t end)
{
	int pivot_position;

	if (start < (int)end)
	{
		pivot_position = lomuto(array, size, start, end);
		sort(array, size, start, (pivot_position - 1));
		sort(array, size, (pivot_position + 1), end);
	}
}

int lomuto(int *array, size_t size, int start, size_t end)
{

	int i, pivot;
	size_t j;

	i = ((int)start - 1);
	pivot = array[end];

	for (j = start; j < end; j++)
		if (array[j] < pivot)
		{
			i++;
			if (i != (int)j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	if ((i + 1) != (int)end)
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

void swap(int *position1, int *position2)
{
	int temp;

	temp = *position1;
	*position1 = *position2;
	*position2 = temp;
}
