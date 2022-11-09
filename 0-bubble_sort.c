#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	unsigned int n, temp, flag = 1;

	if (!array)
		return;

	while (flag == 1 && n != size)
		for (n = 0, flag = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				temp = array[n + 1], array[n + 1] = array[n], array[n] = temp;
				print_array(array, size), flag = 1;	
			}
		}
}
