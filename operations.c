/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:04 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/19 18:29:04 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list *swap(t_list *list)
{
    if (list_size(list) <= 1 || !list)
        return (list);
    t_list *head;
    head= list->next;
    list->next = head->next;    
    head->next = list;
    // if (list->identif == 'b')
    //     write(1, "sb\n", 3);
    // else
    //     write(1, "sa\n", 3);
    return (head);
}
t_list *sa(t_list *list)
{
    t_list *new_list;
    
    new_list = swap(list);
    write(1,"sa\n", 3);
    return(new_list);
}

t_list *sb(t_list *list)
{
    t_list *new_list;
    
    new_list = swap(list);
    write(1,"sb\n", 3);
    return(new_list);
}
void    ss(t_list **list_a ,t_list **list_b )
{
    *list_a = swap(*list_a);
    *list_b = swap(*list_b);
    write(1, "ss\n", 3);
    
}
// void    push(t_list **list_a, t_list **list_b)
// {
//     if (*list_a == NULL)
//         return;
//     if ((*list_b)->identif == 'b')
//         write(1, "pb\n", 3);
//     else
//         write(1, "pa\n", 3);
//     *list_b = add_front(*list_b, (*list_a)->value);
//     *list_a = delete_head(*list_a);
// }

void    pb(t_list **list_a, t_list **list_b)
{
    // if (*list_a == NULL)
    //     return;
        write(1, "pb\n", 3);
    // printf("%p", (list_b));
    *list_b = add_front(*list_b, (*list_a)->value);
    
    // printf("%d", (*list_b)->value);
    *list_a = delete_head(*list_a);
}
void    pa(t_list **list_a, t_list **list_b)
{
    if (*list_b == NULL)
        return;
    write(1, "pa\n", 3);
    *list_a = add_front(*list_a, (*list_b)->value);
    *list_b = delete_head(*list_b);
}

void rotate(t_list **list)
{
    if (*list == NULL || list_size(*list) == 1)
        return;
    if ((*list)->identif == 'b')
        write(1, "rb\n", 3);
    else
        write(1, "ra\n", 3);
    add_back(*list, (*list)->value);
    (*list) = (*list)->next;
}

void ra(t_list **list)
{
     if (*list == NULL || list_size(*list) == 1)
        return;
    write(1, "ra\n", 3);
    add_back(*list, (*list)->value);
    (*list) = (*list)->next;
}

void rb(t_list **list)
{
     if (*list == NULL || list_size(*list) == 1)
        return;
    write(1, "rb\n", 3);
    add_back(*list, (*list)->value);
    (*list) = (*list)->next;
}

void rr(t_list **list_a, t_list **list_b)
{
    rotate(list_a);
    rotate(list_b);
    write(1, "rr\n", 3);
}
void rrotate(t_list **list)
{
    t_list *last_node;
    
    if (*list == NULL)
        return;
    if ((*list)->identif == 'b')
        write(1, "rrb\n", 4);
    else
        write(1, "rra\n", 4);
    last_node = last_one(*list);
    *list = add_front(*list, last_node->value);
    delete_last(list);
}

void rrb(t_list **list)
{
    t_list *last_node;
    
    if (*list == NULL)
        return;
    write(1, "rrb\n", 4);
    last_node = last_one(*list);
    *list = add_front(*list, last_node->value);
     delete_last(list);
    // free(last_node);
}

void rra(t_list **list)
{
    t_list *last_node;
    
    if (*list == NULL)
        return;
    write(1, "rra\n", 4);
    last_node = last_one(*list);
    *list = add_front(*list, last_node->value);
     delete_last(list);
    // free(last_node);
}

void rrr(t_list **list_a, t_list **list_b)
{
    rrotate(list_a);
    rrotate(list_b);
    write(1, "rrr\n", 4);
}



// int main()
// {
//     t_list *list_a = new_list(10 , 'a');
//     // printf("%c\n", list_a->identif);
//     printf("----------------------------------------------\n");
//     // printf("%s --------- %s", list->value, list->next);
//     list_a = add_front(list_a, 11);
//     add_back(list_a, 12);
//     // list = sa(list);
//     // list_a = last_one(list_a);
//     printf("%d\n", list_a->value);
//     printf("%d\n", list_a->next->value);
//     printf("%d\n", list_a->next->next->value);
//     printf("-----------------A---------------\n");
//     // printf("%d", list_size(list_a));
//     t_list *list_b;
//     list_b = malloc(sizeof(t_list));
//     list_b->value= 2;
//     list_b->identif = 'b';
//     list_b->next = malloc(sizeof(t_list));
//     list_b->next->value= 3;
//     list_b->next->next = malloc(sizeof(t_list));
//     list_b->next->next->value = 4;
//     list_b->next->next->next = NULL;
//     // list_b = last_one(list_b);
//     printf("%d\n" ,list_b->value);
//     printf("%d\n" ,list_b->next->value);
//     printf("%d\n" ,list_b->next->next->value);
//     printf("-----------------B---------------\n");
//     // list_b = sb(list_b);
//     // push(&list_a, &list_b);
//     // printf("----------------------B----------------------\n");
//     // printf("%d\n" ,list_b->value);
//     // printf("%d\n" ,list_b->next->value);
//     // printf("%d\n" ,list_b->next->next->value);
//     // list_a = sa(list_a);
//     // printf("----------------------A----------------------\n");
//     // printf("%d\n", list_a->value);
//     // printf("%d\n", list_a->next->value);
//     // printf("%d\n", list_a->next->next->value);
//     // ss(&list_a, &list_b);
//     // list_a = delete_head(list_a);
//     // list_b = delete_head(list_b);
//     // printf("-------PUSH-------\n");
//     // push(&list_a, &list_a);
//     printf("\n%d\n" ,list_b->value);
//     printf("%d\n" ,list_b->next->value);
//     printf("%d\n" ,list_b->next->next->value);
//     printf("%d\n" ,list_b->next->next->next->value);
//     printf("-----------------A---------------\n");
//     printf("%d\n", list_a->value);
//     printf("%d\n", list_a->next->value);
//     // printf("%d\n", list_a->next->next->value);
//     // rr(&list_a, &list_b);
//     // printf("-----------------A---------------\n");
//     // printf("%d\n", list_a->value);
//     // printf("%d\n", list_a->next->value);
//     // printf("%d\n", list_a->next->next->value);
//     // printf("----------------------B----------------------\n");
//     // // rotate(&list_b);
//     // printf("%d\n" ,list_b->value);
//     // printf("%d\n" ,list_b->next->value);
//     // printf("%d\n" ,list_b->next->next->value);
//     // rrr(&list_a, &list_b);
//     // printf("-----------------A---------------\n");
//     // printf("%d\n", list_a->value);
//     // printf("%d\n", list_a->next->value);
//     // printf("%d\n", list_a->next->next->value);
//     // printf("----------------------B----------------------\n");
//     // // rotate(&list_b);
//     // printf("%d\n" ,list_b->value);
//     // printf("%d\n" ,list_b->next->value);
//     // printf("%d\n" ,list_b->next->next->value);
//     return (0);
// }