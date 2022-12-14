#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *second_elem, *cur, *stitch_front, *stitch_back;
	int swap_tick = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	cur = *list;
	while (swap_tick == 1 && cur)
		for (cur = *list, swap_tick = 0; cur && cur->next; cur = cur->next)
		{
			if (cur->n > cur->next->n)		
			{
				second_elem = cur->next;
				stitch_front = second_elem->next;	
				stitch_back = second_elem->prev;	
				second_elem->prev->next = stitch_front;
				if (second_elem->next)
					second_elem->next->prev = stitch_back;

				for (; second_elem->n > cur->n; cur = cur->prev)
					if (!cur->prev)
						break;
				if (cur->prev)
				{
					cur->prev->next = second_elem, second_elem->next = cur;
					second_elem->prev = cur->prev, cur->prev = second_elem;
				}
				else
				{
					second_elem->prev = NULL, second_elem->next = cur;
					cur->prev = second_elem, *list = second_elem;
				}
				print_list(*list), swap_tick = 1;
			}
			if (swap_tick == 1)
				break;
		}
}
