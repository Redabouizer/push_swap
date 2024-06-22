/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:25:46 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 16:59:38 by rbouizer         ###   ########.fr       */
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
    t_stack *Stack_A = NULL;
    int i = 1;

    if (argc > 1)
    {
        while (i < argc)
        {
            if (filter_number(argv[i]) != 0)
            {
                ft_printf("ERREUR\n");
                return 1;
            }
            if (process_tokens(&Stack_A, argv[i]) != 0)
                return 1;
            i++;
        }

        if (rep_number(Stack_A))
        {
            ft_lstclear(&Stack_A, free);
            return 1;
        }

        ft_printf("list\n");
        t_stack *current = Stack_A;
        while (current != NULL)
        {
            ft_printf("%s\n", (char *)current->content);
            current = current->next;
        }

        ft_lstclear(&Stack_A, free);
    }

    return 0;
}




