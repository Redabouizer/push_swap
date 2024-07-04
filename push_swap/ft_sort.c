/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 03:04:08 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/27 22:31:10 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void ft_sort2(t_stack **list_A, char c)
{
    ft_swap(list_A, c);
}

void ft_sort3(t_stack **list_A, char ch)
{
    if (ft_check_sort(*list_A) == 0)
    {
        int a = (*list_A)->index;
        int b = (*list_A)->next->index;
        int c = (*list_A)->next->next->index;

        if (a > b && b > c)
        {
            ft_swap(list_A, ch);
            ft_reverse_rotate(list_A, ch);
        }
        else if (a > c && c > b)
        {
            ft_rotate(list_A, ch);
        }
        else if (a > b && c > a)
        {
            ft_swap(list_A, ch);
        }
        else if (b > a && a > c)
        {
            ft_swap(list_A, ch);
            ft_rotate(list_A, ch);
            ft_swap(list_A, ch);
        }
        else if (b > c && c > a)
        {
            ft_reverse_rotate(list_A, ch);
            ft_swap(list_A, ch);
        }
        else if (c > a && a > b)
        {
            ft_reverse_rotate(list_A, ch);
        }
    }
}

void ft_sort5(t_stack **list_A, t_stack **list_B)
{
    int pushed = 0;

    while (pushed < 2)
    {
        if ((*list_A)->index < 2)
        {
            ft_push(list_B, list_A, 'b');
            pushed++;
        }
        else
        {
            ft_rotate(list_A, 'a');
        }
    }

    ft_sort3(list_A, 'a');

    if (ft_check_sort(*list_B) == 1)
    {
        ft_sort2(list_B, 'b');
    }

    while (*list_B)
    {
        ft_push(list_A, list_B, 'a');
    }
}

bool is_in_upper_half(t_stack *b, int index)
{
    t_stack *tmp;
    int size;
    int i;

    tmp = b;
    i = 0;
    size = ft_lstsize(b);
    while (tmp && i++ < size / 2)
    {
        if (tmp->index == index)
            return (true);
        tmp = tmp->next;
    }
    return (false);
}

void sort_stack(t_stack **list_A, t_stack **list_B)
{
    int pivot1;
    int pivot2;

    pivot2 = 0;
    while (ft_lstsize(*list_A) > 3)
    {
        pivot1 = (ft_lstsize(*list_A) / 6) + pivot2;
        pivot2 += ft_lstsize(*list_A) / 3;
        while (ft_lstsize(*list_B) < pivot2 && ft_lstsize(*list_A) > 3)
        {
            if (*list_B && (*list_A)->index >= pivot2 && (*list_B)->index < pivot1)
                ft_rotate_a_b(list_A, list_B);
            else if (*list_B && (*list_B)->index < pivot1)
                ft_rotate(list_B, 'b');
            if ((*list_A)->index >= pivot2)
                ft_rotate(list_A, 'b');
            else if ((*list_A)->index < pivot2)
                ft_push(list_B, list_A, 'b');
        }
    }
}

void sort_stack_pro(t_stack **list_A, t_stack **list_B)
{
    int max = ft_lstlast(*list_A)->index;

    while (ft_lstsize(*list_B) > 0)
    {
        if (*list_B && (*list_A)->index - 1 == (*list_B)->index)
            ft_push(list_A, list_B, 'a');
        else if (*list_B && (*list_A)->index - 1 == ft_lstlast(*list_B)->index)
        {
            ft_reverse_rotate(list_B, 'b');
            ft_push(list_A, list_B, 'a');
        }
        else if (ft_lstlast(*list_A)->index == max)
        {
            ft_push(list_A, list_B, 'a');
            ft_rotate(list_A, 'a');
        }
        else if (*list_B && ft_lstlast(*list_A)->index < (*list_B)->index)
        {
            ft_push(list_A, list_B, true);
            ft_rotate(list_A, true);
        }
        else if (*list_B && ft_lstlast(*list_A)->index < ft_lstlast(*list_B)->index)
        {
            ft_reverse_rotate(list_B, 'b');
            ft_push(list_A, list_B, 'a');
            ft_rotate(list_A, 'a');
        }
        else if ((*list_A)->index - 1 == ft_lstlast(*list_A)->index)
            ft_reverse_rotate(list_A, 'a');
        else if (*list_B && is_in_upper_half(*list_B, (*list_A)->index - 1))
            ft_rotate(list_B, 'b');
        else
            ft_reverse_rotate(list_B, 'b');
    }
}

void ft_sort_node(t_stack **list_A, t_stack **list_B)
{

    if (ft_check_sort(*list_A) == 0)
    {
        int nb;
        nb = ft_lstsize(*list_A);
        ft_sort_index(*list_A);

        if (nb == 2)
            ft_sort2(list_A, 'a');
        else if (nb == 3)
            ft_sort3(list_A, 'a');
        else if (nb == 5)
            ft_sort5(list_A, list_B);
        else
        {
            sort_stack(list_A, list_B);
            ft_sort3(list_A, 'a');
            sort_stack_pro(list_A, list_B);
        }
    }
}
