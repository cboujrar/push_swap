/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:36:10 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/03 16:12:54 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	read_and_check(t_list *list_a, t_list *list_b)
{
	char	*c;

	c = get_next_line(0);
	while (c != NULL)
	{
		check_operation(list_a, list_b, c);
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
	else if (ac == 2 && first(av, &list_a))
		read_and_check(list_a, list_b);
	else if (ac > 2 && second(av, &list_a))
		read_and_check(list_a, list_b);
	check_and_write(list_a, list_b);
	free(list_a);
	free(list_b);
	return (0);
}
