/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:07:20 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/04 09:36:10 by cboujrar         ###   ########.fr       */
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
			if (!(is_integer(av[i][j])))
			{
				print_error();
				return (0);
			}
			j++;
		}
		if (!(int_range(av[i])))
		{
			print_error();
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsin_1(char *av, char **tab)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(is_integer(av[i])))
		{
			print_error();
			return (0);
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		if (!(int_range(tab[i])))
		{
			print_error();
			return (0);
		}
		i++;
	}
	return (1);
}

int	first(char **av, t_list **list)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(av[1]);
	if (!parsin_1(av[1], tab))
		return (0);
	while (tab[i])
	{
		append(list, ft_atoi(tab[i]));
		i++;
	}
	if (error_check(*list))
		return (0);
	free(tab);
	return (1);
}

int	second(char **av, t_list **list)
{
	int	i;

	i = 1;
	if (!parsin_2(av))
		return (0);
	while (av[i])
	{
		append(list, ft_atoi(av[i]));
		i++;
	}
	if (error_check(*list) && is_quote(*list))
		return (0);
	return (1);
}
