/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:02:49 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/10 19:37:26 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_operation(t_list **list_a, t_list **list_b, char *c)
{
	if (ft_strcmp(c, "pa\n") == 0)
		pa(list_a, list_b);
	else if (ft_strcmp(c, "pb\n") == 0)
		pb(list_a, list_b);
	else if (ft_strcmp(c, "sa\n") == 0)
		*list_a = sa(*list_a);
	else if (ft_strcmp(c, "sb\n") == 0)
		*list_b = sb(*list_b);
	else if (ft_strcmp(c, "ss\n") == 0)
		ss(list_a, list_b);
	else if (ft_strcmp(c, "ra\n") == 0)
		ra(list_a);
	else if (ft_strcmp(c, "rb\n") == 0)
		rb(list_b);
	else if (ft_strcmp(c, "rra\n") == 0)
		rra(list_a);
	else if (ft_strcmp(c, "rrb\n") == 0)
		rrb(list_b);
	else if (ft_strcmp(c, "rr\n") == 0)
		rr(list_a, list_b);
	else if (ft_strcmp(c, "rr\n") == 0)
		rrr(list_a, list_b);
	else
		print_and_exit();
}

void	check_and_write(t_list *list_a, t_list *list_b)
{
	if (list_b == NULL && is_sort(list_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	first_bonus(char **av, t_list **list)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(av[1]);
	while (tab[i])
	{
		append(list, ft_atoi(tab[i]));
		i++;
	}
	free(tab);
	return (1);
}

int	second_bonus(char **av, t_list **list)
{
	int	i;

	i = 1;
	while (av[i])
	{
		append(list, ft_atoi(av[i]));
		i++;
	}
	return (1);
}
