/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:57:04 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/15 02:55:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("Index: %d, Content: %d\n", stack->index, stack->content);
        stack = stack->next;
    }
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;

    stack_a = NULL; 
    stack_b = NULL;
    i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            if (process_tokens(&stack_a, argv[i]) != 0)
                return (free_memory(stack_a), 1);
            i++;
        }
        if (rep_number(stack_a))
            return (free_memory(stack_a), 1);
        ft_sort_index(stack_a);
        ft_check(&stack_a, &stack_b);
        print_stack(stack_a);
        if (ft_check_sort(stack_a) == 1)
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
    }
    return (free_memory(stack_a), free_memory(stack_b), 0);
}