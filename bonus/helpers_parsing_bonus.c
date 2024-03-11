/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_parsing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:45:55 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/11 10:49:02 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_range(char **tab)
{
	int	j;

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
	return (1);
}

int	check_integer(char *av)
{
	int	j;

	j = 0;
	if (check_signe(av[j], av[j + 1]) == 1)
		j++;
	while (av[j])
	{
		if (!(is_integer(av[j])))
		{
			print_error();
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_signe(char c, char a)
{
	if ((c == '+' || c == '-') && (a >= '0' && a <= '9'))
		return (1);
	return (0);
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
