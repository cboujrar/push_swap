/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:26 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/29 23:58:07 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsin_2(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (is_alpha(av[i][j]))
			{
				print_error();
				return(0) ;
			}
			j++;
		}
		if (!(int_range(av[i])))
		{
			print_error();
			return(0) ;
		}
		i++;
	}
	return(1);
}

int	parsin_1(char *av, char **tab)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (is_alpha(av[i]))
		{
			print_error();
			return(0) ;
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		if (!(int_range(tab[i])))
		{
			print_error();
			return(0);
		}
		i++;
	}
	return(1);
}

int	first(char **av, t_list **list)
{
	int		i;
	char 	**tab;

	i = 0;
	tab = ft_split(av[1]);
	if (!parsin_1(av[1], tab))
		return(0);
	while (tab[i])
	{
		append(list, ft_atoi(tab[i]));
		i++;
	}
	if (error_check(*list))
		return(0) ;
	return(1);
}

int	second(char **av, t_list **list)
{
	int	i;

	i = 1;
	if (!parsin_2(av))
		return(0);
	while (av[i])
	{
		append(list, ft_atoi(av[i]));
		i++;
	}
	if (error_check(*list))
		return(0) ;
	return(1);
}

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
	free(list_a);
	free(list_b);
	return (0);
}
