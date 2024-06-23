/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:36:09 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 22:21:14 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *ft_lstnew(int index, int content)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
    {
        ft_printf("Memory allocation error\n");
        exit(1);
    }
    
    ft_printf("hfxcdrjgv\n");
    new_node->content = content;
    new_node->index = index;
    new_node->next = NULL;

    return new_node;
}

