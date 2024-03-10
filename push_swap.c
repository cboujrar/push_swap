/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:26 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/10 17:05:47 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (ac < 2)
	{
		print_error();
		return (0);
	}
	else if (ac == 2 && first(av, &list_a))
	{
		push_to_b(&list_a, &list_b);
		push_back_to_a(&list_a, &list_b);
	}
	else if (ac > 2 && second(av, &list_a))
	{
		push_to_b(&list_a, &list_b);
		push_back_to_a(&list_a, &list_b);
	}
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
