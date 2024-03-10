/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:05:01 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/10 19:39:05 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **list)
{
	if (*list == NULL || list_size(*list) == 1)
		return ;
	add_back(*list, (*list)->value);
	(*list) = (*list)->next;
}

void	rb(t_list **list)
{
	if (*list == NULL || list_size(*list) == 1)
		return ;
	add_back(*list, (*list)->value);
	(*list) = (*list)->next;
}

void	rrb(t_list **list)
{
	t_list	*last_node;

	if (*list == NULL)
		return ;
	last_node = last_one(*list);
	add_front(list, last_node->value);
	delete_last(list);
}

void	rra(t_list **list)
{
	t_list	*last_node;

	if (*list == NULL)
		return ;
	last_node = last_one(*list);
	add_front(list, last_node->value);
	delete_last(list);
}

void	pa(t_list **list_a, t_list **list_b)
{
	if (*list_b == NULL)
		return ;
	add_front(list_a, (*list_b)->value);
	*list_b = delete_head(*list_b);
}
