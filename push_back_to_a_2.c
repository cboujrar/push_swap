/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:21:43 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/10 19:32:19 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_three(t_list **list_a, t_list **list_b, int j, t_initial **p)
{
	if ((*list_a)->value < (*list_b)->value)
	{
		ra(list_a);
		(*p)->down++;
	}
	else
		find_and_push(list_a, list_b, j, p);
}

void	reverse_rotate(t_list **list_a, t_initial **p)
{
	rra(list_a);
	(*p)->down--;
	(*p)->tracker--;
}
