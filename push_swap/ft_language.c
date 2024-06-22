/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_language.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:16:00 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/22 16:43:36 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void ft_swap(t_stack **stack, char c)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    
    void *temp_content = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = temp_content;

    if (c == 'a')
        ft_printf("sa\n");
    else if (c == 'b')
        ft_printf("sb\n");
}

void ft_swap_a_b(t_stack **stack_A, t_stack **stack_B)
{
    ft_swap(stack_A, 'c');
    ft_swap(stack_B, 'c');
    ft_printf("ss\n");
}

void ft_push(t_stack **stack_A, t_stack **stack_B, char c)
{
    if (*stack_B == NULL)
        return;

    t_stack *node_to_move = *stack_B;
    *stack_B = node_to_move->next;
    node_to_move->next = *stack_A;
    *stack_A = node_to_move;

    if (c == 'a')
        ft_printf("pa\n");
    else if (c == 'b')
        ft_printf("pb\n");
}

void ft_rotate(t_stack **stack, char c)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_stack *last = ft_lstlast(*stack);
    t_stack *first = *stack;

    *stack = first->next;
    first->next = NULL;
    last->next = first;

    if (c == 'a')
        ft_printf("ra\n");
    else if (c == 'b')
        ft_printf("rb\n");
}

void ft_rotate_a_b(t_stack **stack_A, t_stack **stack_B)
{
    ft_rotate(stack_A, 'c');
    ft_rotate(stack_B, 'c');
    ft_printf("rr\n");
}

void ft_reverse_rotate(t_stack **stack, char c)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_stack *last = ft_lstlast(*stack);
    t_stack *second_last = *stack;

    while (second_last->next != last)
    {
        second_last = second_last->next;
    }

    second_last->next = NULL;
    last->next = *stack;
    *stack = last;

    if (c == 'a')
        ft_printf("rra\n");
    else if (c == 'b')
        ft_printf("rrb\n");
}

void ft_reverse_rotate_a_b(t_stack **stack_A, t_stack **stack_B)
{
    ft_reverse_rotate(stack_A, 'c');
    ft_reverse_rotate(stack_B, 'c');
    ft_printf("rrr\n");
}












// void show(t_list *list, const char *name)
// {
//     ft_printf("%s: ", name);
//     while (list)
//     {
//         ft_printf("%d ", (int)(list->content));
//         list = list->next;
//     }
//     ft_printf("\n");
// }

// int main(void)
// {
//     t_list *list_A = NULL;
//     t_list *list_B = NULL;

//     ft_lstadd_front(&list_A, ft_lstnew((void *)1));
//     ft_lstadd_front(&list_A, ft_lstnew((void *)2));
//     ft_lstadd_front(&list_A, ft_lstnew((void *)3));
//     ft_lstadd_front(&list_B, ft_lstnew((void *)6));
//     ft_lstadd_front(&list_B, ft_lstnew((void *)5));
//     ft_lstadd_front(&list_B, ft_lstnew((void *)8));

//     show(list_A, "Initial List A");
//     show(list_B, "Initial List B");

//     ft_printf("-----------------------------------------\n");
//     ft_swap(&list_A, 'a');
//     show(list_A, "After ft_swap_a (List A)");
//     ft_printf("-----------------------------------------\n");

//     ft_swap(&list_B, 'b');
//     show(list_B, "After ft_swap_b (List B)");
//     ft_printf("-----------------------------------------\n");

//     ft_swap_a_b(&list_A, &list_B);
//     show(list_A, "After ft_swap_a_b (List A)");
//     show(list_B, "After ft_swap_a_b (List B)");

//     ft_printf("-----------------------------------------\n");
//     ft_push(&list_A, &list_B,'a');
//     show(list_A, "After ft_push_a (List A)");
//     show(list_B, "After ft_push_a (List B)");
//     ft_printf("-----------------------------------------\n");

//     ft_push(&list_B, &list_A,'b');
//     show(list_A, "After ft_push_b (List A)");
//     show(list_B, "After ft_push_b (List B)");

//     ft_printf("-----------------------------------------\n");
//     ft_rotate(&list_A,'a');
//     show(list_A, "After ft_rotate_a (List A)");
//     ft_printf("-----------------------------------------\n");

//     ft_rotate(&list_B,'b');
//     show(list_B, "After ft_rotate_b (List B)");
//     ft_printf("-----------------------------------------\n");

//     ft_rotate_a_b(&list_A, &list_B);
//     show(list_A, "After ft_rotate_a_b (List A)");
//     show(list_B, "After ft_rotate_a_b (List B)");
//     ft_printf("-----------------------------------------\n");

//     ft_reverse_rotate(&list_A,'a');
//     show(list_A, "After ft_reverse_rotate_a (List A)");
//     ft_printf("-----------------------------------------\n");

//     ft_reverse_rotate(&list_B,'b');
//     show(list_B, "After ft_reverse_rotate_b (List B)");
//     ft_printf("-----------------------------------------\n");

//     ft_reverse_rotate_a_b(&list_A, &list_B);
//     show(list_A, "After ft_reverse_rotate_a_b (List A)");
//     show(list_B, "After ft_reverse_rotate_a_b (List B)");
//     ft_printf("-----------------------------------------\n");

//     ft_lstclear(&list_A, free);
//     ft_lstclear(&list_B, free);

//     return 0;
// }