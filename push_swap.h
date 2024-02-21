/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:08:39 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/20 15:29:14 by cboujrar         ###   ########.fr       */
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

void sort_array(int *arr , int size);
int *create_sorted_array(t_list *list);
int check_index(t_list *list, int number);
void push_to_b(t_list **list_a, t_list **list_b);
void push_back_to_a(t_list **list_a, t_list **list_b);
void print_error();
int is_alpha(int c);
int int_range(int c);
int is_duplicate(t_list *list);
int is_sort(t_list *list);
int error_check(t_list *list);
int	ft_atoi(const char *str);
int	count_words(const char *str);
char	*put_word(const char *str, int start, int end);
void	*free_array(char **str, int count);
void	ft_initiate_vars(size_t *i, int *j, int *s_word);
char	**ft_split(const char *s);
t_list* new_list(int value , char a);
t_list *add_front(t_list *list, int value);
t_list *last_one(t_list *list);
void add_back(t_list *list, int value);
int list_size(t_list *list);
t_list *delete_head(t_list *list);
void delete_last(t_list **list);
t_list *swap(t_list *list);
t_list *sa(t_list *list);
t_list *sb(t_list *list);
void    ss(t_list **list_a ,t_list **list_b );
void    pb(t_list **list_a, t_list **list_b);
void    pa(t_list **list_a, t_list **list_b);
void rotate(t_list **list);
void ra(t_list **list);
void rb(t_list **list);
void rr(t_list **list_a, t_list **list_b);
void rrotate(t_list **list);
void rrb(t_list **list);
void rra(t_list **list);
void rrr(t_list **list_a, t_list **list_b);
void print_list(t_list *list);
void append(t_list **list, int value);

#endif