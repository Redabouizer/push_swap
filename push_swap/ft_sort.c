/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 03:04:08 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/23 23:52:52 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    if (nb % 2 == 1)
        moy = (nb / 2) + 1;
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
        {
            return 0;
        }

        min_node->index = index++;
    }
}

void ft_sort2(t_stack **list_A, char c)
{
    ft_swap(list_A, c);
}

int ft_sort3(t_stack **list_A, char ch)
{
    int a = (*list_A)->content;
    int b = (*list_A)->next->content;
    int c = (*list_A)->next->next->content;

    if (a < b && a < c)
    {
        ft_swap(list_A, ch);
        ft_rotate(list_A, ch);
    }
    else if (a > b && a < c)
        ft_swap(list_A, ch);
    else if (a < b && a > c)
        ft_reverse_rotate(list_A, ch);
    else if (a > b && a > c)
    {
        ft_rotate(list_A, ch);
        if (b > c)
            ft_swap(list_A, ch);
    }
    return 1;
}

void ft_sort5(t_stack **list_A, t_stack **list_B) {
    int in = find_index(*list_A, 2);
    ft_printf("%d  \n", in);

    t_stack *current = *list_A;
    int pushed = 0;


    while (pushed < 2 && current) {
        if (current->content < in) {
            ft_push(list_B, list_A, 'b');
            pushed++;
        } else {
            ft_rotate(list_A, 'a');
            current = *list_A;
        }
    }

    
    ft_sort3(list_A, 'a');

    if (ft_check_sort(*list_B) == -1) {
        ft_sort2(list_B, 'b');
    }

    // while (*list_B) {
    //     ft_push(list_A, list_B, 'a'); // Push all elements from list_B back to list_A
    // }
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
    int nb;

    ft_lstadd_back(&list_A, ft_lstnew(-1, 10));
    ft_lstadd_back(&list_A, ft_lstnew(-1, 8));
    ft_lstadd_back(&list_A, ft_lstnew(-1, 2));
    ft_lstadd_back(&list_A, ft_lstnew(-1, 7));
    ft_lstadd_back(&list_A, ft_lstnew(-1, 5));

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

    nb = ft_lstsize(list_A);
    ft_sort_index(list_A);
    show(list_A, "Initial List A");
    show(list_B, "Initial List B");
    if (nb == 2)
    {
        ft_sort2(&list_A, 'a');
    }
    else if (nb == 3)
    {
        ft_sort3(&list_A, 'a');
    }
    else if (nb == 5)
    {
        ft_sort5(&list_A, &list_B);
    }

    show(list_A, "Initial List A");
    show(list_B, "Initial List B");

    return 0;
}
