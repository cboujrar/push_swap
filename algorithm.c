/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:51:48 by cboujrar          #+#    #+#             */
/*   Updated: 2024/02/19 17:49:18 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// void	intialize(int midd, int offset, int div, int start, int end,
// 		t_list *list_a)
// {
// 	int		i;
// 	t_list	*tracker;

// 	tracker = list_a;
// 	i = 0;
// 	midd = list_size(list_a) / 2;
// 	while (i < midd)
// 	{
// 		tracker = tracker->next;
// 		i++;
// 	}
// 	div = tracker->value;
// 	offset = list_size(list_a) / midd;
// 	start = midd - offset;
// 	end = midd + offset;
//     printf("\nmidd ---> %d\n", midd);
//     printf("div ---> %d\n", div);
//     printf("offset ---> %d\n", offset);
//     printf("start ---> %d\n", start);
//     printf("end ---> %d\n", end);    
// }

// void	push_to_b(t_list **list_a, t_list **list_b)
// {
// 	int	midd;
// 	int	offset;
// 	int	start;
// 	int	end;
// 	int	div;
//     int i;
//     t_list *tracker;

//     printf("I am here");
//     int		j;
// 	t_list	*tr;

// 	tr = *list_a;
// 	j = 0;
// 	midd = list_size(*list_a) / 2;
// 	while (j < midd)
// 	{
// 		tr = tr->next;
// 		j++;
// 	}
// 	div = tr->value;
// 	offset = list_size(*list_a) / midd;
// 	start = midd - offset;
// 	end = midd + offset;
// 	// intialize(midd, offset, div, start, end, *list_a);
//     printf("\nmidd ---> %d\n", midd);
//     printf("div ---> %d\n", div);
//     printf("offset ---> %d\n", offset);
//     printf("start ---> %d\n", start);
//     printf("end ---> %d\n", end); 
//     while ((*list_a)->next)
//     {
//         // tracker = *list_a;
//         if(*list_a && ((*list_a)->value >= start && (*list_a)->value <= end))
//         {
//                 push(list_a, list_b);
//         }
//             i = 0;
//         while(*list_a && (!((*list_a)->value >= start && (*list_a)->value <= end)))
//         {
//             printf("hhh----");
//             *list_a = (*list_a)->next;
//             i++;
//         }
//         if (i < 4 / 2)
//         {
//              printf("%d--------", i);
//             while (i > 0)
//             {
//                 rotate(list_a);
//                 // printf("%d--------", i);
//                 i--;
//             }
//         } 
//         // *list_a = (*list_a)->next;
//     }
// }

// void push_to_b(t_list **list_a, t_list **list_b)
// {
//     int midd;
//     int offset;
//     int start;
//     int end;
//     int pivot;
//     int size;
//     int i;
//     t_list *tracker;
   
//     size = list_size(*list_a);
//     midd = size / 2;
//     pivot = (*list_a)->value;
//     offset = size / pivot;
//     start = midd - offset;
//     end = midd + offset;
//     while (*list_a)
//     {
//         if ((*list_a)->value >= start && (*list_a)->value <= end)
//             push(list_a, list_b);
//         else
//         {
//             tracker = (*list_a);
//             i = 0;
//             while (tracker && !((tracker->value >= start && tracker->value <= end)))
//             {
//                 tracker = tracker->next;
//                 i++;
//             }
//             printf("%d", tracker->value);
//             if (tracker == NULL)
//             {
//                 start = start - offset;
//                 end = end + offset;    
//                 printf("%d", start);
//                 printf("\n%d", end);    

//             }
//             while (i > 0)
//             {
//                 rotate(list_a);
//                 i--;
//             }
//         }
//     }
// }

void sort_array(int *arr , int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr [j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
             j++;
        }
        i++;
    }
}

int *create_sorted_array(t_list *list)
{
    int i;
    int *arr;
    int size;
    
    i = 0;
    size = list_size(list);
    arr = malloc(size * sizeof(int));
    if (!arr)
        return (NULL);
    while (list)
    {
        arr[i] = list->value;
        list = list->next;
        i++;
    }    
    sort_array(arr, size);
    return (arr);
}
int check_index(t_list *list, int number)
{
    int i;

    i = 0;
    while (list)
    {
        if (list->value == number)
            return (i);
        else
            i++;
            list = list->next;
    }
    return (-1);
}

void push_to_b(t_list **list_a, t_list **list_b)
{
    int size;
    int pivot;
    int midd;
    int start;
    int end;
    int offset;
    int i;
    int *sorted_array;
    int j;
    t_list * tracker;
    int top;
    // t_list *current;


    sorted_array = create_sorted_array(*list_a);
    size = list_size(*list_a);
    if (size <= 10)
        pivot = 5;
    else if (size <= 150 )
        pivot = 8;
    else 
        pivot = 18;
    midd = size / 2 - 1;
    offset = size / pivot;
    start = midd - offset;
    end = midd + offset;
    printf("offset is %d\n", offset);
    printf("start is %d\n", start);
    printf("end is %d\n", end);
    printf("midd is %d\n", midd);
    printf("size is %d\n", size);
    
    // current = *list_a;
    while (*list_a)
    {
        top = (*list_a)->value;
        // printf("----top = %d\n", top);
        if (top >= sorted_array[start] && top <= sorted_array[end])
        {
            pb(list_a, list_b);
            if (top < sorted_array[midd])
                rotate(list_b);
        }
            
        else 
        {
            // printf("knt hna \n");
            tracker = (*list_a);
            while (tracker && !(tracker->value >= sorted_array[start] && tracker->value <= sorted_array[end]))
                tracker = tracker->next;
            if (tracker)
            {
                j = check_index((*list_a) , tracker->value);
                // printf("l index : %d\n", j);
                if ( j < size / 2)
                {
                    while (j--)
                        rotate(list_a);
                }
                else if ( j >= size / 2)
                {
                    j = list_size(*list_a) - j;
                    while (j--)
                        rrotate(list_a);
                }
                pb(list_a, list_b);
                if ((*list_b)->next != NULL && tracker->value < sorted_array[midd])
                    rb(list_b);
            }
            if (tracker)
                tracker = tracker->next;
            else 
            {
                start = start -  offset;
                end = end + offset;
                if (start < 0)
                    start = 0;
                if (end >= size -1)
                    end = size - 1;
                // printf("start is %d\n", start);
                // printf("end is %d\n", end);
            }
        }
        // current = current->next;
    }
    free(sorted_array);
}

void push_back_to_a(t_list **list_a, t_list **list_b)
{
    int down;
    int size;
    int *sorted_array;
    int tracker;
    int j; 

    size = list_size(*list_b);
    printf("size---> %d\n", size);
    down = 0;
    tracker = size - 1;
    sorted_array= create_sorted_array(*list_b);
  
    while(*list_b || tracker >= 0)
    {
        // printf("max --> %d\n", sorted_array[tracker]);
        // printf(" tracker-->%d\n", tracker);
        j = check_index(*list_b, sorted_array[tracker]);
        // printf("j--> %d\n", j);
        if ((*list_a) == NULL)
        {
                if (j < size / 2)
                {
                    while (j--)
                        rb(list_b);
                }
                else if(j > size / 2)
                {
                    j = size - j;
                    while (j--)
                        rrb(list_b);
                }
                pa(list_a, list_b);
                tracker--;
        }
        else if (j != -1)
        {
            // printf("value --> %d\n", (*list_b)->value);
            if ((*list_b)->value == sorted_array[tracker])
            {
                 pa(list_a, list_b);
                 tracker--;
            }
            else if (down == 0 || (*list_b)->value > (last_one(*list_a))->value)
            {
                pa(list_a, list_b);
                ra(list_a);
                down++;
                // printf("dzt mn hna 111\n");
            }
            else
            {
                // printf("dzt mn hna \n");
                if (j < size / 2)
                {
                    while (j--)
                        rb(list_b);
                }
                else if(j >= size / 2)
                {
                    j = list_size(*list_b) - j;
                    while (j--)
                        rrb(list_b);
                }
                pa(list_a, list_b);
                 tracker--;
            } 
        }
        else
        {
            rra(list_a);
            down--;
            tracker--;
        }
    }   
     free(sorted_array); 
}

// int main()
// {
//     t_list *list_a;
//     list_a = malloc(sizeof(t_list));
//     list_a->value= 1;
//     list_a->identif = 'a';
//     list_a->next = malloc(sizeof(t_list));
//     list_a->next->value= 10;
//     list_a->next->next = malloc(sizeof(t_list));
//     list_a->next->next->value = 4;
//     list_a->next->next->next = malloc(sizeof(t_list));
//     list_a->next->next->next->value = 20;
//     t_list *list_b;
//     // list_b = NULL;
//     list_b = malloc(sizeof(t_list));
//     list_b->next= NULL;
//     list_b->identif = 'b';
//     if (!list_b)
//         return (1);
//     push(&list_a, &list_b);
//     // push_to_b(&list_a, &list_b);
//     while (list_b) 
//     {
//         printf("______%d______\n", list_b->value);
//         list_b = list_b->next;
//     }

//     printf("----------------------------\n"); 
//     while (list_a)
//     {
//         printf("%d\n", list_a->value);
//         list_a = list_a->next;
//     } 
//     return(0);
// }

void append(t_list **list, int value) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return;

    new_node->value = value;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        t_list *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(t_list *list) {
    while (list != NULL) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

int main(int ac , char **av) {
    t_list *list_a = NULL;
    t_list *list_b = NULL;
    int *arr;
    int i = 0;
    
    // list_b = malloc(sizeof(t_list));
    // list_b->identif = 'b';
    // printf("-----%d-----", list_b->value);
    append(&list_a, 1);
    append(&list_a, 5);
    append(&list_a, 17);
    append(&list_a, 0);
    append(&list_a, 2);
    // append(&list_a, 8);
    // append(&list_a, 3);
    // append(&list_a, 15);
    // append(&list_a, 9);
    // append(&list_a, 6);
    // append(&list_a, 22);
    // append(&list_a, 4);
    // append(&list_a, 32);
    // append(&list_a, 10);
    // append(&list_a, 25);
    // append(&list_a, 11);
    // append(&list_a, 24);
    // while(av[i] != NULL)
    // {
    //     append(&list_a, *av[i]);
    //     i++;
    // }
    list_a->identif = 'a';
    arr = create_sorted_array(list_a);

    printf("Initial list_a: ");
    print_list(list_a);
    // printf("----------\n");
    // while (i < list_size(list_a))
    // {
    //     printf("%d\n", arr[i]);
    //     i++;
    // }
    // printf("-----------\n");
    // push(&list_a, &list_b);
    // printf("list B : %d\n", list_b->value);
    // printf("list A %d\n", list_a->value);
    // printf("-----%d\n" , check_index(arr, 2, 4, 9));
    // printf("%p \n",&list_b);
    list_a->identif = 'a';
    push_to_b(&list_a, &list_b);
    list_b->identif= 'b';
    
    printf("Modified list_a: ");
    print_list(list_a);
    printf("list_b: ");
    print_list(list_b);
    push_back_to_a(&list_a, &list_b);
     printf("Modified list_a: ");
    print_list(list_a);
    printf("list_b: ");
    print_list(list_b);
    return 0;
}