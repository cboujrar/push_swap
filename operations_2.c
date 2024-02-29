/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:27:26 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/25 18:31:21 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list)
{
	if (*list == NULL || list_size(*list) == 1)
		return ;
	write(1, "ra\n", 3);
	add_back(*list, (*list)->value);
	(*list) = (*list)->next;
}

void	rb(t_list **list)
{
	if (*list == NULL || list_size(*list) == 1)
		return ;
	write(1, "rb\n", 3);
	add_back(*list, (*list)->value);
	(*list) = (*list)->next;
}

void	rrb(t_list **list)
{
	t_list	*last_node;

	if (*list == NULL)
		return ;
	write(1, "rrb\n", 4);
	last_node = last_one(*list);
	*list = add_front(*list, last_node->value);
	delete_last(list);
}

void	rra(t_list **list)
{
	t_list	*last_node;

	if (*list == NULL)
		return ;
	write(1, "rra\n", 4);
	last_node = last_one(*list);
	*list = add_front(*list, last_node->value);
	delete_last(list);
}

void	pa(t_list **list_a, t_list **list_b)
{
	if (*list_b == NULL)
		return ;
	write(1, "pa\n", 3);
	*list_a = add_front(*list_a, (*list_b)->value);
	*list_b = delete_head(*list_b);
}
