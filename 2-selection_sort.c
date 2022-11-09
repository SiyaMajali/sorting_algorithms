#include "sort.h"
#include <stdio.h>


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
			temp = array[i];
			array[i] = minval;
			array[minindex] = temp;
			print_array(array, size);
			flag = 0;
		}
	}
}
