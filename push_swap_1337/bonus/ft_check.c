/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:07:14 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/15 03:39:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int first_s(t_stack **list_A, t_stack **list_B, char *str)
{
    int i = 1;

    if (str[i] == 'a' && str[i + 1] == '\n')
        ft_swap(list_A, 'a');
    else if (str[i] == 'b' && str[i + 1] == '\n')
        ft_swap(list_B, 'b');
    else if (str[i] == 's' && str[i + 1] == '\n')
        ft_swap_a_b(list_A, list_B);
    else
        return 1;
    return 0;
}

int first_p(t_stack **list_A, t_stack **list_B, char *str)
{
    int i = 1;

    if (str[i] == 'a' && str[i + 1] == '\n')
        ft_push(list_A, list_B, 'a');
    else if (str[i] == 'b' && str[i + 1] == '\n')
        ft_push(list_B, list_A, 'b');
    else
        return 1;
    return 0;
}

int first_r(t_stack **list_A, t_stack **list_B, char *str)
{
    int i = 1;

    if (str[i] == 'a' && str[i + 1] == '\n')
        ft_rotate(list_A, 'a');
    else if (str[i] == 'b' && str[i + 1] == '\n')
        ft_rotate(list_B, 'b');
    else if (str[i] == 'r')
    {
        if (str[i] == 'r' && str[i + 1] == '\n')
            ft_rotate_a_b(list_A, list_B);
        else if (str[i] == 'r' && str[i + 1] != '\n')
        {
            i++;
            if (str[i] == 'a' && str[i + 1] == '\n')
                ft_reverse_rotate(list_A, 'a');
            else if (str[i] == 'b' && str[i + 1] == '\n')
                ft_reverse_rotate(list_B, 'b');
            else if (str[i] == 'r' && str[i + 1] == '\n')
                ft_reverse_rotate_a_b(list_A, list_B);
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return 1;
    return 0;
}

int ft_check(t_stack **list_A, t_stack **list_B)
{
    int e;
    char *str;

    e = 0;
    while ((str = get_next_line(0)) != NULL)
    {
        printf(" hd asli %s\n" , str);
        if (str[0] == 's')
            e = first_s(list_A, list_B, str);
        else if (str[0] == 'p')
            e = first_p(list_A, list_B, str);
        else if (str[0] == 'r')
            e = first_r(list_A, list_B, str);
        else
        {
            free(str);
            return 1;
        }
        free(str);
        if (e == 1)
            return 1;
    }
    return 0;
}
