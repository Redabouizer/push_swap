/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:57:54 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/17 01:57:56 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_a_b(t_stack **stack_A, t_stack **stack_B)
{
	ft_reverse_rotate(stack_A, 'c');
	ft_reverse_rotate(stack_B, 'c');
	write(1, "rrr\n", 4);
}
