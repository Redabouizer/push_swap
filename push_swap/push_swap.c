/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:25:46 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/28 19:26:39 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void f()
// {
//     system("leaks push_swap");
// }

void show(t_stack *list, const char *name)
{
    ft_printf("%s: ", name);
    while (list)
    {
        ft_printf("(%d  %d)", list->index, list->content);
        list = list->next;
    }
    ft_printf("\n");
}

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
            {
                free_memory(stack_A);
                return 1;
            }
            i++;
        }

        if (rep_number(stack_A))
        {
            free_memory(stack_A);
            return 1;
        }
        ft_sort_index(stack_A);
        ft_sort_node(&stack_A, &stack_B);

    }
    show(stack_A, "Initial List A");
    show(stack_B, "Initial List B");

    free_memory(stack_A);
    free_memory(stack_B);

    

    return 0;
}

// mchi mohim

// int randomInteger(int min, int max)
// {
//     if (min > max)
//     {
//         int temp = min;
//         min = max;
//         max = temp;
//     }
//     return rand() % (max - min + 1) + min;
// }

// int is_duplicate(t_stack *stack, int value)
// {
//     while (stack != NULL)
//     {
//         if (stack->content == value)
//             return 1;
//         stack = stack->next;
//     }
//     return 0;
// }

// int main(void)
// {
//     t_stack *list_A = NULL;
//     t_stack *list_B = NULL;
//     int nb;
//     int i = 5;

//     srand(time(NULL));

//     int min = -100;
//     int max = 500;
//     while (i != 0)
//     {
//         int randomNum;
//         do
//         {
//             randomNum = randomInteger(min, max);
//         } while (is_duplicate(list_A, randomNum));
//         ft_lstadd_back(&list_A, ft_lstnew(-1, randomNum));
//         i--;
//     }

//     ft_printf("-------------------\n");

//     if (ft_check_sort(list_A) == 0)
//     {
//         ft_printf("no sort\n");
//     }
//     else
//     {
//         ft_printf("sort\n");
//         show(list_A, "Initial List A");
//         return 0;
//     }

//     nb = ft_lstsize(list_A);
//     ft_sort_index(list_A);
//     show(list_A, "Initial List A");
//     show(list_B, "Initial List B");
//     ft_sort_node(&list_A, &list_B);

//     show(list_A, "Initial List A");
//     show(list_B, "Initial List B");

//     return 0;
// }
