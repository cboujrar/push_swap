/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:10:19 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/04 14:58:10 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_and_push(t_list **list_a, t_list **list_b, int j, t_initial **p)
{
	if (j < (*p)->size / 2)
	{
		while (j--)
			rb(list_b);
	}
	else if (j >= (*p)->size / 2)
	{
		j = (*p)->size - j;
		while (j--)
			rrb(list_b);
	}
	pa(list_a, list_b);
	(*p)->tracker--;
}

void	initialise(t_initial **p, t_list **list_b)
{
	(*p)->size = list_size(*list_b);
	(*p)->down = 0;
	(*p)->tracker = (*p)->size - 1;
	(*p)->sorted_array = create_sorted_array(*list_b);
}

void	push_to_a(t_list **list_a, t_list **list_b, t_initial **p, int j)
{
	if ((*list_b)->value == (*p)->sorted_array[(*p)->tracker])
	{
		pa(list_a, list_b);
		(*p)->tracker--;
	}
	else if ((*p)->down == 0 || (*list_b)->value > (last_one(*list_a))->value)
	{
		pa(list_a, list_b);
		ra(list_a);
		(*p)->down++;
	}
	else
	{
		(*p)->size = list_size(*list_b);
		find_and_push(list_a, list_b, j, p);
	}
}

void	push_back_to_a(t_list **list_a, t_list **list_b)
{
	int			j;
	t_initial	*p;

	if (*list_b == NULL)
		return;
	p = malloc(sizeof(t_initial));
	if (!p)
		return ;
	initialise(&p, list_b);
	while (*list_b || p->tracker >= 0)
	{
		j = check_index(*list_b, p->sorted_array[p->tracker]);
		if (list_size(*list_a) == 3)
		{
			if ((*list_a)->value < (*list_b)->value)
			{
				ra(list_a);
				p->down++;
			}
			else 
			find_and_push(list_a, list_b, j, &p);	
		}
		else if (j != -1)
			push_to_a(list_a, list_b, &p, j);
		else
		{
			rra(list_a);
			p->down--;
			p->tracker--;
		}
	}
	if (p->down > 0)
		rra(list_a);
	free(p);
}
