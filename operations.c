/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:04 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/25 18:31:47 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *list)
{
	t_list	*head;

	if (list_size(list) <= 1 || !list)
		return (list);
	head = list->next;
	list->next = head->next;
	head->next = list;
	return (head);
}

t_list	*sa(t_list *list)
{
	t_list	*new_list;

	new_list = swap(list);
	write(1, "sa\n", 3);
	return (new_list);
}

t_list	*sb(t_list *list)
{
	t_list	*new_list;

	new_list = swap(list);
	write(1, "sb\n", 3);
	return (new_list);
}

void	ss(t_list **list_a, t_list **list_b)
{
	*list_a = swap(*list_a);
	*list_b = swap(*list_b);
	write(1, "ss\n", 3);
}

void	pb(t_list **list_a, t_list **list_b)
{
	if (*list_a == NULL)
		return ;
	write(1, "pb\n", 3);
	*list_b = add_front(*list_b, (*list_a)->value);
	*list_a = delete_head(*list_a);
}
