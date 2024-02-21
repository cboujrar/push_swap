/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:58:23 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/20 15:21:34 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error()
{
    write(1, "ERROR\n", 6);
}

int is_alpha(int c)
{
    if ((c > 65 && c < 90 ) || (c > 97 && c < 122))
        return (1);
    return (0);
}

int int_range(int c)
{
    if (c > -2147483648 && c <= 2147483647)
        return (1);
    return(0);
}

int is_duplicate(t_list *list)
{
    int temp;
    t_list *current;
    t_list *checker;
    
    if (!list)
        return(0);
    current = list;
    while (current)
    {
        temp = current->value;
        checker = current->next;
        while (checker)
        {
            if (temp == checker->value)
                  return(1);
            checker = checker->next;
        }
        current = current->next;
    }
    return(0);
}

int is_sort(t_list *list)
{
    if (!list)
        return(0);
    while (list->next)
    {
        if (list->value < list->next->value)
            list = list->next;
        else 
            return (0);
    }
    return(1);
}

int error_check(t_list *list)
{
    if (is_duplicate(list) || is_sort(list))
    {
        print_error();
        return(1);
    }
    while (list)
    {
        if (is_alpha(list->value) && !int_range(list->value))
        {
            print_error();
            return(1);        
        }
        else
            list =list->next;
    }
    return (0);
}

// int main ()
// {
//     t_list *list;
    
//     list = malloc(sizeof(t_list));
//     list->value = 17;
//     list->next = malloc(sizeof(t_list));
//     list->next->value = 2;
//     list->next->next = malloc(sizeof(t_list));
//     list->next->next->value = 5;
//     // if (is_duplicate(list))
//     //     print_error();
//     // else 
//     //     printf("Good!\n");
//     // printf ("----------------\n");
//     // if (is_sort(list))
//     //     print_error();
//     // else 
//     //     printf("you can continue to sort them\n");
//     if (error_check(list))
//         printf("change the list please");
//     else
//         printf("no error");
//     return(0);
// }