/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:47:59 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 19:22:03 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void ft_lstadd_front(t_stack **lst, t_stack *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}



