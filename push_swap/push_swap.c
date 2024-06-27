/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:25:46 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/27 00:46:27 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void  f()
// {
//     system("leaks push_swap");
// }



int main(int argc, char *argv[])
{
    // atexit(f);
    t_stack *stack_A = NULL;
    t_stack *stack_B = NULL;
    int i = 1;

    if (argc > 1)
    {
        while (i < argc)
        {
            if (process_tokens(&stack_A, argv[i]) != 0)
                return 1;
            i++;
        }

        if (rep_number(stack_A))
            return 1;

        ft_sort_node( &stack_A , &stack_B );
                      
    //     ft_printf("%s: ","liste");
    // while (stack_A)
    // {
    //     ft_printf("(%d  %d)", stack_A->index, stack_A->content);
    //     stack_A = stack_A->next;
    // }
    // ft_printf("\n");
    }
    return 0;
}
