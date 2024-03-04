/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:03:54 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/03 15:59:47 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	return (new_list);
}

t_list	*sb(t_list *list)
{
	t_list	*new_list;

	new_list = swap(list);
	return (new_list);
}

void	ss(t_list **list_a, t_list **list_b)
{
	*list_a = swap(*list_a);
	*list_b = swap(*list_b);
}

void	pb(t_list **list_a, t_list **list_b)
{
	if (*list_a == NULL)
		return ;
	*list_b = add_front(*list_b, (*list_a)->value);
	*list_a = delete_head(*list_a);
}
