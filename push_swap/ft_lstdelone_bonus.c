/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:00:48 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/23 15:03:55 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstdelone(t_stack *lst, void (*del)(void *))
{
    if (lst && del)
    {
        intptr_t content_as_ptr = (intptr_t)lst->content;
        del((void *)content_as_ptr);
        free(lst);
    }
}


