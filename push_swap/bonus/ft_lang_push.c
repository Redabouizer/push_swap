/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:54:16 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/18 07:55:41 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*node_to_move;

	if (*stack_B == NULL)
		return ;
	node_to_move = *stack_B;
	*stack_B = node_to_move->next;
	node_to_move->next = *stack_A;
	*stack_A = node_to_move;
}
