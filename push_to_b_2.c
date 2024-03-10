/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:13:10 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/04 14:41:41 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_range(t_parameters *p, int value)
{
	if (value >= p->sorted_array[p->start] && value <= p->sorted_array[p->end])
		return (1);
	return (0);
}

void	push_and_rotate(t_list **list_a, t_list **list_b, int midd,
		t_list *tracker)
{
	pb(list_a, list_b);
	if ((*list_b)->next != NULL && tracker->value < midd)
		rb(list_b);
}

void	find_number(t_list **list_a, t_list **list_b, int *array,
		t_parameters **p)
{
	t_list	*tracker;
	int		j;

	tracker = (*list_a);
	while (tracker && !(is_in_range(*p, tracker->value)))
		tracker = tracker->next;
	if (tracker)
	{
		j = check_index((*list_a), tracker->value);
		if (j < (*p)->size / 2)
		{
			while (j--)
				ra(list_a);
		}
		else if (j >= (*p)->size / 2)
		{
			j = list_size(*list_a) - j;
			while (j--)
				rra(list_a);
		}
		push_and_rotate(list_a, list_b, array[(*p)->midd], tracker);
	}
	if (!tracker)
		re_init_param(p);
}

void sort_three(t_list **list)
{
    int first = (*list)->value;
    int second = (*list)->next->value;
    int third = (*list)->next->next->value;

    if (first < second && second < third)
        return; 
    if (first > second && first > third)
	{
        if (second > third) 
		{
            ra(list);
			*list = sa(*list);
        } 
		else 
            ra(list);
    } 
	else if (first > second && first < third)
		*list = sa(*list);
	else if (first > third && first < second)
        rra(list);
	else if (first < second && second > third)
	{
		rra(list);
		*list = sa(*list);
	}
}



void	push_to_b(t_list **list_a, t_list **list_b)
{
	t_parameters	*p;
	int				top;

	p = malloc(sizeof(t_parameters));
	if (!p)
		return ;
	init_param(&p, *list_a);
	if (list_size(*list_a) <= 3)
			sort_three(list_a);
	else
	{
		while (list_size(*list_a) > 3)
		{
			top = (*list_a)->value;
			if (is_in_range(p, top))
			{
				pb(list_a, list_b);
				if (top < p->sorted_array[p->midd])
					rb(list_b);
			}
			else
				find_number(list_a, list_b, p->sorted_array, &p);
		}
		sort_three(list_a);
	}
	free(p);
}
