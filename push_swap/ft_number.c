/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:14:25 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 22:29:21 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_memory(t_stack *list)
{
    t_stack *temp;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}


int rep_number(t_stack *Stack_A)
{
    t_stack *i = Stack_A;
    while (i != NULL)
    {
        t_stack *j = i->next;
        while (j != NULL)
        {
            if (i->content == j->content)
            {
                ft_printf("ERREUR\n");
                return 1;
            }
            j = j->next;
        }
        i = i->next;
    }
    return 0;
}

