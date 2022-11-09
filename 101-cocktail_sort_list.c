#include "sort.h"
#include <stdio.h>

void swap_node(listint_t **list, listint_t *node1, listint_t *node2);

void cocktail_sort_list(listint_t **list)
{
	listint_t *mover, *bubble_up, *bubble_down;
	int start = 0, end = 0, moving = 0, sort = 1, min, max;

	if (!list || !(*list) || !(*list)->next)
		return; 
	mover = *list; 
	while (mover->next != NULL)
	{
		mover = mover->next;
		end++;
		if (mover->prev->n > mover->n)
			sort = 0;
	}
	if (sort == 1)
		return;
	mover = (*list);
	while (start < end)
	{
		max = mover->n;
		while (moving < end)
		{
			mover = mover->next;
			if (mover->n > max)
			{
				max = mover->n; 
				bubble_up = mover;
			}
			else
			{ 
				swap_node(list, bubble_up, mover);
				mover = bubble_up;
				print_list(*list);
			}
			moving++;
		}
		end--;
		min = mover->n;
		while (moving > start)
		{
			mover = mover->prev;
			if (mover->n < min)
			{
				min = mover->n;
				bubble_down = mover;
			}
			else
			{
				swap_node(list, mover, bubble_down);
				print_list(*list);
				mover = bubble_down;
			}
			moving--;
		}
		start++;
	}
}

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		(*list) = node2;
	node2->prev = node1->prev;
	node1->prev = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->next = node1;
}
