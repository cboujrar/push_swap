/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:19 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/29 23:59:52 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_and_push(t_list **list_a, t_list **list_b, int j, int size, int *tracker)
{
	if (j < size / 2)
	{
		while (j--)
			rb(list_b);
	}
	else if (j > size / 2)
	{
		j = size - j;
		while (j--)
			rrb(list_b);
	}
	pa(list_a, list_b);
	(*tracker)--;
}

void	initialise(t_initial **p, t_list **list_b)
{
	(*p)->size = list_size(*list_b);
	(*p)->down = 0;
	(*p)->tracker = (*p)->size - 1;
	(*p)->sorted_array = create_sorted_array(*list_b);
	(*p)->j = check_index(*list_b, (*p)->sorted_array[(*p)->tracker]);
}

void	push_back_to_a(t_list **list_a, t_list **list_b)
{
	t_initial *p;

	p = malloc(sizeof(t_initial));
	if (!p)
		return;
	initialise(&p, list_b);
	while (*list_b || p->tracker >= 0)
	{
		p->j = check_index(*list_b, p->sorted_array[p->tracker]);
		if ((*list_a) == NULL)
			find_and_push(list_a, list_b, p->j, p->size, &(p->tracker));
		else if (p->j != -1)
		{
			if ((*list_b)->value == p->sorted_array[p->tracker])
			{
				pa(list_a, list_b);
				p->tracker--;
			}
			else if (p->down == 0 || (*list_b)->value > (last_one(*list_a))->value)
			{
				pa(list_a, list_b);
				ra(list_a);
				p->down++;
			}
			else
				find_and_push(list_a, list_b, p->j, list_size(*list_a), &(p->tracker));
		}
		else
		{
			rra(list_a);
			p->down--;
			p->tracker--;
		}
	}
	free(p->sorted_array);
}


void	append(t_list **list, int value)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
	}
	else
	{
		current = *list;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%d ", list->value);
		list = list->next;
	}
	printf("\n");
}