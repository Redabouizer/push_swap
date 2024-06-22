/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 03:04:08 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 19:23:09 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int ft_check_sort(t_list *list_A)
// {
//     while (list_A && list_A->next)
//     {
//         if ((int)(list_A->content) > (int)(list_A->next->content))
//         {
//             return 0;
//         }
//         list_A = list_A->next;
//     }
//     return 1;
// }

void show(t_stack *list, const char *name)
{
    ft_printf("%s: ", name);
    while (list)
    {
        ft_printf("%d", list->content);
        list = list->next;
    }
    ft_printf("\n");
}




int main(void)
{
    t_stack *list_A = NULL;
    t_stack *list_B = NULL;

    ft_lstadd_front(&list_A, ft_lstnew(1, 1));
    ft_lstadd_front(&list_A, ft_lstnew(2, 2));
    ft_lstadd_front(&list_A, ft_lstnew(3, 3));
    ft_lstadd_front(&list_B, ft_lstnew(0, 6));
    ft_lstadd_front(&list_B, ft_lstnew(5, 5));
    ft_lstadd_front(&list_B, ft_lstnew(6, 8));

    show(list_A, "Initial List A");
    show(list_B, "Initial List B");

    return 0;
}






