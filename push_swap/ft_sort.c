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

int find_min(t_stack *stack)
{
    int min = stack->content;
    t_stack *current = stack;
    while (current != NULL)
    {
        if (current->content < min)
        {
            min = current->content;
        }
        current = current->next;
    }
    return min;
}

int find_index(t_stack *list, int ind)
{
    while (list != NULL)
    {
        if (list->index == ind)
            return list->content;
        list = list->next;
    }
    return -1;
}

int ft_moyen_number(int nb)
{
    int moy;
    moy = nb / 2;
    return moy;
}

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

int ft_sort_index(t_stack *list_A)
{

    t_stack *current;
    t_stack *min_node;
    int min_value;
    int index = 0;

    while (1)
    {
        current = list_A;
        min_node = NULL;
        min_value = __INT_MAX__;
        while (current)
        {
            if (current->index == -1 && current->content < min_value)
            {
                min_value = current->content;
                min_node = current;
            }
            current = current->next;
        }
        if (!min_node)
            return 0;

        min_node->index = index++;
    }
}

void ft_sort2(t_stack **list_A, char c)
{
    ft_swap(list_A, c);
}

void ft_sort3(t_stack **h, char ch)
{

    int n[3];

    (1) && (n[0] = (*h)->index, n[1] = (*h)->next->index);
    n[2] = (*h)->next->next->index;
    if (n[1] < n[0] && n[1] < n[2] && n[0] < n[2])
        ft_swap(h, ch);
    else if (n[2] < n[1] && n[2] < n[0] && n[0] > n[1])
    {
        ft_swap(h, ch);
        ft_reverse_rotate(h, ch);
    }
    else if (n[1] < n[0] && n[1] < n[2] && n[0] > n[2])
        ft_rotate(h,ch);
    else if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
    {
        ft_swap(h, ch);
        ft_rotate(h, ch);
    }
    else if (n[2] < n[0] && n[2] < n[1] && n[0] < n[1])
        ft_reverse_rotate(h, ch);
}

void ft_sort5(t_stack **list_A, t_stack **list_B)
{
    int pushed = 0;

    while (pushed < 2 && *list_A)
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
    if (ft_check_sort(*list_B) == 0)
    {
        ft_sort3(list_A, 'a');
    }

    if (ft_check_sort(*list_B) != 0)
    {
        ft_sort2(list_B, 'b');
    }

    while (*list_B)
    {
        ft_push(list_A, list_B, 'a');
    }
}

void sort_stack(t_stack **a, t_stack **b)
{
    int pivo1;
    int pivo2;

    pivo2 = 0;
    while (ft_lstsize(*a) > 3)
    {
        pivo1 = (ft_lstsize(*a) / 6) + pivo2;
        pivo2 += ft_lstsize(*a) / 3;
        while (ft_lstsize(*b) < pivo2 && ft_lstsize(*a) > 3)
        {
            if (*b && (*a)->index >= pivo2 && (*b)->index < pivo1)
                ft_rotate_a_b(a, b);
            else if (*b && (*b)->index < pivo1)
                ft_rotate(b, 'b');
            if ((*a)->index >= pivo2)
                ft_rotate(a, 'b');
            else if ((*a)->index < pivo2)
                ft_push(b, a, 'b');
        }
    }
}

bool is_in_up(t_stack *b, int index)
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

void sort_stack_pro(t_stack **a, t_stack **b)
{
    int max;

    max = ft_lstlast(*a)->index;
    while (ft_lstsize(*b) > 0)
    {
        if (*b && (*a)->index - 1 == (*b)->index)
            ft_push(a, b, 'a');
        else if (*b && (*a)->index - 1 == ft_lstlast(*b)->index)
        {
            ft_reverse_rotate(b, 'b');
            ft_push(a, b, 'a');
        }
        else if (ft_lstlast(*a)->index == max)
        {
            ft_push(a, b, 'a');
            ft_rotate(a, 'a');
        }
        else if (*b && ft_lstlast(*a)->index < (*b)->index)
        {
            ft_push(a, b, true);
            ft_rotate(a, true);
        }
        else if (*b && ft_lstlast(*a)->index < ft_lstlast(*b)->index)
        {
            ft_reverse_rotate(b, 'b');
            ft_push(a, b, 'a');
            ft_rotate(a, 'a');
        }
        else if ((*a)->index - 1 == ft_lstlast(*a)->index)
            ft_reverse_rotate(a, 'a');
        else if (*b && is_in_up(*b, (*a)->index - 1))
            ft_rotate(b, 'b');
        else
            ft_reverse_rotate(b, 'b');
    }
}

int ft_sort_node(t_stack **list_A, t_stack **list_B)
{
    int nb;

    if (ft_check_sort(*list_A) != 0)
    {
        return 0;
    }

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

    return 0;
}