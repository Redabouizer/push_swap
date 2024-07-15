/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:53 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/15 20:05:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack **stack)
{
	int	temp_content;
	int	temp_index;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp_content = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp_content;
	temp_index = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp_index;
}

void	ft_swap_a_b(t_stack **stack_A, t_stack **stack_B)
{
	ft_swap(stack_A);
	ft_swap(stack_B);
}