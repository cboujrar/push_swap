/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:07:20 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/10 19:55:06 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsin_2(char **av)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	while (av[i])
	{
		j = 0;
		if ((av[i][j] == '+' || av[i][j] == '-') && (av[i][j + 1] >= '0'
				&& av[i][j + 1] <= '9'))
			j++;
		while (av[i][j])
		{
			if (!(is_integer(av[i][j])))
			{
				print_error();
				return (0);
			}
			j++;
		}
		tab = ft_split(av[i]);
		if (!tab)
		{
			print_error();
			return (0);
		}
		j = 0;
		while (tab[j])
		{
			if (!(int_range(tab[j])))
			{
				print_error();
				free_tab(tab);
				return (0);
			}
			j++;
		}
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
		if ((av[i] == '+' || av[i] == '-') && (av[i + 1] >= '0' && av[i+ 1] <= '9'))
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

int	is_empty(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] == ' ' || av[1][i] == '\t') && (av[1][i + 1] == ' '
				|| av[1][i + 1] == '\t'))
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

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
