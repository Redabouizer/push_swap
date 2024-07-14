/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:53 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/10 23:45:06 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rotate_a_b(t_stack **stack_A, t_stack **stack_B)
{
	ft_rotate(stack_A, 'c');
	ft_rotate(stack_B, 'c');
	write(1, "rr\n", 3);
}
