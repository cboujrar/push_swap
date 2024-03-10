/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:47:13 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/10 16:38:56 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_list **list, int value)
{
	t_list	*my_list;

	my_list = malloc(sizeof(t_list));
	if (!my_list)
		return ;
	my_list->value = value;
	my_list->next = *list;
	*list = my_list;
}

t_list	*last_one(t_list *list)
{
	if (!list)
		return (0);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	add_back(t_list *list, int value)
{
	t_list	*my_list;

	if (!list)
		return ;
	my_list = malloc(sizeof(t_list));
	if (!my_list)
		return ;
	my_list->value = value;
	my_list->next = NULL;
	while (list->next != NULL)
		list = list->next;
	list->next = my_list;
}

int	list_size(t_list *list)
{
	int	size;

	if (!list)
		return (0);
	size = 0;
	while (list != NULL)
	{
		list = list->next;
		size++;
	}
	return (size);
}

void	append(t_list **list, int value)
{
	t_list	*new_node;
	t_list	*current;

	current = NULL;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*list == NULL)
		*list = new_node;
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
