/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:14:25 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 19:28:42 by rbouizer         ###   ########.fr       */
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



int filter_number(const char *token)
{
    int j;
    long num;

    j = 0;
    if (!token || *token == '\0')
        return 1;

    num = ft_atoi(token);
    if (num > INT_MAX || num < INT_MIN)
        return 1;
    if ((token[j] == '+' || token[j] == '-') &&
        (token[j + 1] >= '0' && token[j + 1] <= '9'))
    {
        j++;
    }
    while (token[j])
    {
        if (token[j] < '0' || token[j] > '9')
            return 1;
        j++;
    }
    return 0;
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


void ft_stack(t_stack **Stack_A, int content)
{
    t_stack *node = ft_lstnew(0, content);
    if (!node)
    {
        ft_printf("ERREUR\n");
        exit(1);
    }
    ft_lstadd_back(Stack_A, node);
}
