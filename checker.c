/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:58:23 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/29 19:40:50 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_list *list)
{
	int		temp;
	t_list	*current;
	t_list	*checker;

	if (!list)
		return (0);
	current = list;
	while (current)
	{
		temp = current->value;
		checker = current->next;
		while (checker)
		{
			if (temp == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sort(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->value < list->next->value)
			list = list->next;
		else
			return (0);
	}
	return (1);
}

int	error_check(t_list *list)
{
	if (is_duplicate(list) || is_sort(list))
	{
		print_error();
		return (1);
	}
	return (0);
}
