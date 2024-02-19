/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:08:39 by cboujrar          #+#    #+#             */
/*   Updated: 2024/01/27 15:51:29 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

typedef struct s_list{
    int value;
    char    identif;
    struct s_list *next;
}   t_list;

t_list* new_list(int value , char a);
t_list *add_front(t_list *list, int value);
void add_back(t_list *list, int value);
t_list *last_one(t_list *list);
int list_size(t_list *list);
t_list *delete_head(t_list *list);
t_list *swap(t_list *list);
t_list *sa(t_list *list);
t_list *sb(t_list *list);
void    ss(t_list **list_a ,t_list **list_b );
void    push(t_list **list_a, t_list **list_b);
void rotate(t_list **list);
void print_error();
int is_alpha(int c);
int int_range(int c);
int is_duplicate(t_list *list);
int is_sort(t_list *list);
int error_check(t_list *list);

#endif