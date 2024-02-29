/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:05:48 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/25 18:07:17 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*delete_head(t_list *list)
{
	t_list	*new_list;

	new_list = list->next;
	free(list);
	return (new_list);
}

void	delete_last(t_list **list)
{
	t_list	*temp;

	temp = *list;
	if (*list == NULL)
	{
		return ;
	}
	else if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}
