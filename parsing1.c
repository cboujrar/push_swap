/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:58:23 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/04 09:39:38 by cboujrar         ###   ########.fr       */
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
	free(checker);
	free(current);
	return (0);
}

int	is_sort(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	error_check(t_list *list)
{
	if (is_duplicate(list))
	{
		print_error();
		return (1);
	}
	else if (is_sort(list))
		return (1);
	return (0);
}

int	is_integer(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ')
		return (1);
	return (0);
}

int	int_range(char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		str++;
	}
	if (sign == 1 && result > 2147483647)
		return (0);
	else if (sign == -1 && - result < -2147483648)
		return (0);
	return (1);
}

int is_quote(t_list *list)
{
	while (list)
	{
		if (list->value == '\"' || list->value == '\'')
			return(1);
		list = list->next;
	}
	return(0);
}
