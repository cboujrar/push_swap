/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:36:10 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/11 13:29:56 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	read_and_check(t_list **list_a, t_list **list_b)
{
	char	*c;

	c = get_next_line(0);
	while (c != NULL)
	{
		check_operation(list_a, list_b, c);
		free(c);
		c = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		if (first(av, &list_a) == 0)
			exit(1);
	}
	else if (ac > 2)
	{
		if (second(av, &list_a) == 0)
			exit(1);
	}
	read_and_check(&list_a, &list_b);
	if (is_sort(list_a) && list_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
