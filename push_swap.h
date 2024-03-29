/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:08:39 by cboujrar          #+#    #+#             */
/*   Updated: 2024/03/11 12:36:53 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "bonus/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_prameters
{
	int				size;
	int				pivot;
	int				midd;
	int				start;
	int				end;
	int				offset;
	int				*sorted_array;
}					t_parameters;

typedef struct s_initial
{
	int				size;
	int				tracker;
	int				down;
	int				*sorted_array;
}					t_initial;

void				sort_array(int *arr, int size);
int					*create_sorted_array(t_list *list);
int					check_index(t_list *list, int number);
void				push_to_b(t_list **list_a, t_list **list_b);
void				push_back_to_a(t_list **list_a, t_list **list_b);
void				print_error(void);
int					is_integer(int c);
int					int_range(char *str);
int					is_duplicate(t_list *list);
int					is_sort(t_list *list);
int					error_check(t_list *list);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					count_words(const char *str);
char				*put_word(const char *str, int start, int end);
void				*free_array(char **str, int count);
void				ft_initiate_vars(size_t *i, int *j, int *s_word);
char				**ft_split(const char *s);
void				add_front(t_list **list, int value);
t_list				*last_one(t_list *list);
int					list_size(t_list *list);
t_list				*delete_head(t_list *list);
void				delete_last(t_list **list);
t_list				*swap(t_list *list);
t_list				*sa(t_list *list);
t_list				*sb(t_list *list);
void				ss(t_list **list_a, t_list **list_b);
void				pb(t_list **list_a, t_list **list_b);
void				pa(t_list **list_a, t_list **list_b);
void				rotate(t_list **list);
void				ra(t_list **list);
void				rb(t_list **list);
void				rrotate(t_list **list);
void				rrb(t_list **list);
void				rra(t_list **list);
void				print_list(t_list *list);
void				append(t_list **list, int value);
int					parsin_2(char **av);
int					parsin_1(char *av, char **tab);
int					first(char **av, t_list **list);
int					second(char **av, t_list **list);
void				init_param(t_parameters **param, t_list *list);
void				re_init_param(t_parameters **p);
int					ft_strcmp(char *s1, char *s2);
void				check_operation(t_list **list_a, t_list **list_b, char *c);
void				check_and_write(t_list *list_a, t_list *list_b);
int					first_bonus(char **av, t_list **list);
int					second_bonus(char **av, t_list **list);
void				free_list(t_list **list);
void				free_parameters(t_parameters *p);
void				rr(t_list **list_a, t_list **list_b);
void				rrr(t_list **list_a, t_list **list_b);
void				handle_three(t_list **list_a, t_list **list_b, int j,
						t_initial **p);
void				reverse_rotate(t_list **list_a, t_initial **p);
void				find_and_push(t_list **list_a, t_list **list_b, int j,
						t_initial **p);
void				free_tab(char **tab);
int					check_signe(char c, char a);
int					check_integer(char *av);
int					check_range(char **tab);
int					is_empty(char **av);
void				print_and_exit(void);

#endif