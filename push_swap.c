/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:26 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/21 01:34:43 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int ac, char **av)
{
    char **tab;
    int i;
    t_list *list_a = NULL;
    t_list *list_b = NULL;
    
    i = 0;
    if(ac == 2)
    {
        tab = ft_split(av[1]);
        while (tab[i])
        {
            printf("%s\n", tab[i]);
            i++;
        }
        i = 0;
        while (tab[i])
        {
            append(&list_a, ft_atoi(tab[i]));
            i++;
        }
    }
    else
    {
        i = 0;
        while (av[i])
        {
            append(&list_a, ft_atoi(av[i]));
            i++;
        }      
    }
    list_a->identif = 'a';
    push_to_b(&list_a, &list_b);
    list_b->identif= 'b';
    // printf("Modified list_a: ");
    // print_list(list_a);
    // printf("list_b: ");
    // print_list(list_b);
    push_back_to_a(&list_a, &list_b);
    printf("Modified list_a: ");
    print_list(list_a);
    printf("list_b: ");
    print_list(list_b);
}