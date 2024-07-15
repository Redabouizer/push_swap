/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:53 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/15 03:30:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack **stack_A, t_stack **stack_B, char c)
{
	t_stack	*node_to_move;

	if (*stack_B == NULL)
		return ;
	node_to_move = *stack_B;
	*stack_B = node_to_move->next;
	node_to_move->next = *stack_A;
	*stack_A = node_to_move;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}