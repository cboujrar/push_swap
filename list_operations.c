/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:47:13 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/19 17:47:53 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<push_swap.h>

t_list* new_list(int value , char a)
{
    t_list *myList;
    myList = malloc(sizeof(t_list));
    if (!myList)
        return 0;
    myList->value = value;
    myList->identif = a;
    myList->next = NULL;   
    return(myList);
}

t_list *add_front(t_list *list, int value)
{
    t_list *myList;
    
    myList = malloc(sizeof(t_list));
    if (!myList)
        return(0);
    myList->value = value;
    myList->next= list;
    return(myList);
}

t_list *last_one(t_list *list)
{
    if (!list)
        return (0);
    while (list->next != NULL)
        list = list->next;
    return (list);    
}

void add_back(t_list *list, int value)
{  
    if (!value || !list)
        return;
    t_list *myList ;
    myList = malloc(sizeof(t_list));
    if (!myList)
        return;
    myList->value = value;
    myList->next = NULL;
    while (list->next != NULL)
        list = list->next;
    list->next = myList;    
}

int list_size(t_list *list)
{
    int size ;
    
    if (!list)
        return(0);
    size = 0;
    while (list != NULL)
    {
        list = list->next;
        size++;
    }
    return(size);
}
t_list *delete_head(t_list *list)
{
    t_list *new_list;

    new_list = list->next;
    free(list);
    return(new_list);
}
void delete_last(t_list **list)
{
    t_list *temp;

    temp = *list;
    if (*list == NULL)
    {
        return; 
    } 
    else if ((*list)->next == NULL)
    {
        free(*list);
        *list = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next); 
    temp->next = NULL;
}