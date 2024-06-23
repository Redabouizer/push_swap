/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_language.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:16:00 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/23 20:51:03 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack **stack, char c)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    
    int temp_content = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = temp_content;

    int temp_index = (*stack)->index;
    (*stack)->index = (*stack)->next->index;
    (*stack)->next->index = temp_index;

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

    t_stack *last = *stack;
    t_stack *first = *stack;

    while (last->next != NULL) {
        last = last->next; 
    }

    *stack = first->next;
    first->next = NULL;
    last->next = first;

    if (c == 'a') {
        printf("ra\n"); 
    } else if (c == 'b') {
        printf("rb\n"); 
    }
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

    t_stack *last = *stack;
    t_stack *second_last = NULL;

    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *stack;
    *stack = last; 
    
    if (c == 'a') {
        printf("rra\n"); 
    } else if (c == 'b') {
        printf("rrb\n"); 
    }
}

void ft_reverse_rotate_a_b(t_stack **stack_A, t_stack **stack_B)
{
    ft_reverse_rotate(stack_A, 'c');
    ft_reverse_rotate(stack_B, 'c');
    ft_printf("rrr\n");
}












// void show(t_stack *list, const char *name)
// {
//     ft_printf("%s: ", name);
//     while (list)
//     {
//         ft_printf("( %d , %d )",list->index,list->content);
//         list = list->next;
//     }
//     ft_printf("\n");
// }

// int main(void)
// {
//     t_stack *list_A = NULL;
//     t_stack *list_B = NULL;

//     ft_lstadd_back(&list_A, ft_lstnew(0, 1));
//     ft_lstadd_back(&list_A, ft_lstnew(2, 3));
//     ft_lstadd_back(&list_A, ft_lstnew(1, 2));
//     ft_lstadd_back(&list_B, ft_lstnew(4, 8));
//     ft_lstadd_back(&list_B, ft_lstnew(3, 7));
//     ft_lstadd_back(&list_B, ft_lstnew(5,9));

//     show(list_A, "Initial List A");
//     show(list_B, "Initial List B");

    // ft_printf("-----------------------------------------\n");
    // ft_swap(&list_A, 'a');
    // show(list_A, "After ft_swap_a (List A)");
    // ft_printf("-----------------------------------------\n");

    // ft_swap(&list_B, 'b');
    // show(list_B, "After ft_swap_b (List B)");
    // ft_printf("-----------------------------------------\n");

    // ft_swap_a_b(&list_A, &list_B);
    // show(list_A, "After ft_swap_a_b (List A)");
    // show(list_B, "After ft_swap_a_b (List B)");

    // ft_printf("-----------------------------------------\n");
    // ft_push(&list_A, &list_B,'a');
    // show(list_A, "After ft_push_a (List A)");
    // show(list_B, "After ft_push_a (List B)");
    // ft_printf("-----------------------------------------\n");

    // ft_push(&list_B, &list_A,'b');
    // show(list_A, "After ft_push_b (List A)");
    // show(list_B, "After ft_push_b (List B)");

    // ft_printf("-----------------------------------------\n");
    // ft_rotate(&list_A,'a');
    // show(list_A, "After ft_rotate_a (List A)");
    // ft_printf("-----------------------------------------\n");

    // ft_rotate(&list_B,'b');
    // show(list_B, "After ft_rotate_b (List B)");
    // ft_printf("-----------------------------------------\n");

    // ft_rotate_a_b(&list_A, &list_B);
    // show(list_A, "After ft_rotate_a_b (List A)");
    // show(list_B, "After ft_rotate_a_b (List B)");
    // ft_printf("-----------------------------------------\n");

    // ft_reverse_rotate(&list_A,'a');
    // show(list_A, "After ft_reverse_rotate_a (List A)");
    // ft_printf("-----------------------------------------\n");

    // ft_reverse_rotate(&list_B,'b');
    // show(list_B, "After ft_reverse_rotate_b (List B)");
    // ft_printf("-----------------------------------------\n");

    // ft_reverse_rotate_a_b(&list_A, &list_B);
    // show(list_A, "After ft_reverse_rotate_a_b (List A)");
    // show(list_B, "After ft_reverse_rotate_a_b (List B)");
    // ft_printf("-----------------------------------------\n");


//     return 0;
// }