/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:26 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/22 19:28:39 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int ac, char **av)
{
    char **tab;
    int i;
    int j;
    t_list *list_a = NULL;
    t_list *list_b = NULL;
    
    i = 0;
    if (ac < 2)
        print_error();
    else if(ac == 2)
    {
        while (av[1][i])
        {
            if (is_alpha(av[1][i]))
            {
                print_error();
                return(0);
            }
            i++;  
        }
        i = 0;
        tab = ft_split(av[1]);
        while(tab[i])
        {
            if (!(int_range(tab[i])))
            {
                print_error();
                return(0);
            }
            i++;
        }
        while (tab[i])
        {
            append(&list_a, ft_atoi(tab[i]));
            i++;
        }
        if (error_check(list_a))
            return(0);
    }
    else
    {
        i = 1;
        j = 0;
        while(av[i])
        {
            while (av[i][j])
            {
                if (is_alpha(av[i][j]))
                {
                    print_error();
                    return(0);
                }
                j++;
            }
            if (!(int_range(av[i])))
            {
                print_error();
                return(0);
            }
            i++;
        }
        i = 1;
        while (av[i])
        {
            append(&list_a, ft_atoi(av[i]));
            i++;
        }   
        if (error_check(list_a))
            return(0);   
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
    return(0);
}