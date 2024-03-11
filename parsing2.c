/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:07:20 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/11 10:45:03 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsin_2(char **av)
{
	int		i;
	char	**tab;

	i = 1;
	while (av[i])
	{
		if (check_integer(av[i]) == 0)
			return (0);
		tab = ft_split(av[i]);
		if (!tab)
		{
			print_error();
			return (0);
		}
		if (check_range(tab) == 0)
			return (0);
		free_tab(tab);
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
		if (check_signe(av[i], av[i + 1]) == 1)
			i++;
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

	if (*av[1] == '\0')
	{
		print_error();
		return (0);
	}
	tab = ft_split(av[1]);
	if (!parsin_1(av[1], tab) || is_empty(av) == 0)
	{
		free_tab(tab);
		return (0);
	}
	i = 0;
	while (tab[i])
	{
		append(list, ft_atoi(tab[i]));
		i++;
	}
	free_tab(tab);
	if (error_check(*list))
		return (0);
	return (1);
}

int	second(char **av, t_list **list)
{
	int		i;
	char	**tab;
	int		j;

	i = 1;
	if (!parsin_2(av))
		return (0);
	while (av[i])
	{
		tab = ft_split(av[i]);
		j = 0;
		while (tab[j])
		{
			append(list, ft_atoi(tab[j]));
			j++;
		}
		free_tab(tab);
		i++;
	}
	if (error_check(*list))
	{
		free_list(list);
		return (0);
	}
	return (1);
}
