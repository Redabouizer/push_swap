/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:07:14 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/11 03:40:18 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void ft_check(t_stack **list_A, t_stack **list_B)
{
    int i;
    char *str;

    str = get_next_line(0);
    while (str != NULL)
    {
        str = get_next_line(0);
        if (str[i] == 's')
        {
            i++;
            if (str[i] == 'a')
                ft_swap(list_A, 'c');
            else if (str[i] == 'b')
                ft_swap(list_A, 'c');
            else if (str[i] == 's')
                ft_swap_a_b(list_A, list_B);
        }
        
    }

    printf("%s", str);
}
