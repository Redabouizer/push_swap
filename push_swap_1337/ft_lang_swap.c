/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:53 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/06 00:40:27 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
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
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_a_b(t_stack **stack_A, t_stack **stack_B)
{
	ft_swap(stack_A, 'c');
	ft_swap(stack_B, 'c');
	write(1, "ss\n", 3);
}
