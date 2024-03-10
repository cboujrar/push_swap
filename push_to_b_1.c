/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:51:48 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/10 19:25:01 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*create_sorted_array(t_list *list)
{
	int	i;
	int	*arr;
	int	size;

	i = 0;
	size = list_size(list);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (list)
	{
		arr[i] = list->value;
		list = list->next;
		i++;
	}
	sort_array(arr, size);
	return (arr);
}

int	check_index(t_list *list, int number)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->value == number)
			return (i);
		else
			i++;
		list = list->next;
	}
	return (-1);
}

void	init_param(t_parameters **param, t_list *list)
{
	(*param)->size = list_size(list);
	if ((*param)->size <= 10)
		(*param)->pivot = 5;
	else if ((*param)->size <= 150)
		(*param)->pivot = 8;
	else
		(*param)->pivot = 20;
	(*param)->midd = (*param)->size / 2 - 1;
	(*param)->offset = (*param)->size / (*param)->pivot;
	(*param)->start = (*param)->midd - (*param)->offset;
	(*param)->end = (*param)->midd + (*param)->offset;
	(*param)->sorted_array = create_sorted_array(list);
}

void	re_init_param(t_parameters **p)
{
	(*p)->start = (*p)->start - (*p)->offset;
	(*p)->end = (*p)->end + (*p)->offset;
	if ((*p)->start < 0)
		(*p)->start = 0;
	if ((*p)->end >= (*p)->size - 4)
		(*p)->end = (*p)->size - 4;
}
