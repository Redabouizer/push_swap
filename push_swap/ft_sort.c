/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 03:04:08 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/23 15:33:26 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_sort(t_stack *list_A)
{
    while (list_A && list_A->next)
    {
        if (list_A->content > list_A->next->content)
        {
            return 0;
        }
        list_A = list_A->next;
    }
    return 1;
}

int ft_sort_index(t_stack *list_A) {
    
    t_stack *current;
    t_stack *min_node;
    int min_value;
    int index = 0;

    while (1) {
        current = list_A;
        min_node = NULL;
        min_value = __INT_MAX__;
        
        while (current) {
            if (current->index == -1 && current->content < min_value) {
                min_value = current->content;
                min_node = current;
            }
            current = current->next;
        }

        if (!min_node)
        {
            return 0;
        } 

        min_node->index = index++;
    }
}


void ft_sort2(t_stack *list_A,char c)
{
    ft_swap(&list_A, c);
}

int ft_sort3(t_stack *list_A)
{
    while (list_A && list_A->next)
    {
        if (list_A->content > list_A->next->content)
        {
            return 0;
        }
        list_A = list_A->next;
    }
    return 1;
}
int ft_sort4(t_stack *list_A)
{
    while (list_A && list_A->next)
    {
        if (list_A->content > list_A->next->content)
        {
            return 0;
        }
        list_A = list_A->next;
    }
    return 1;
}

void show(t_stack *list, const char *name)
{
    ft_printf("%s: ", name);
    while (list)
    {
        ft_printf("(%d  %d)", list->index, list->content);
        list = list->next;
    }
    ft_printf("\n");
}

int main(void)
{
    t_stack *list_A = NULL;
    t_stack *list_B = NULL;

    ft_lstadd_back(&list_A, ft_lstnew(-1, 2));
    ft_lstadd_back(&list_A, ft_lstnew(-1, 1));
    //    ft_lstadd_back(&list_A, ft_lstnew(3, 3));
    //     ft_lstadd_back(&list_A, ft_lstnew(0, 6));
    //     ft_lstadd_back(&list_A, ft_lstnew(5,5));

    show(list_A, "Initial List A");
    show(list_B, "Initial List B");

    ft_printf("-------------------\n");

    if (ft_check_sort(list_A) == 0)
    {
        ft_printf("no sort\n");
    }
    else
    {
        ft_printf("sort\n");
        show(list_A, "Initial List A");
        return 0;
    }

    ft_lstsize(list_A);

    ft_sort2(list_A,'a');
    ft_sort_index(list_A);

    show(list_A, "Initial List A");
    show(list_B, "Initial List B");

    return 0;
}
