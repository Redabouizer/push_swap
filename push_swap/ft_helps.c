/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:50 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/05 23:23:20 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*current;

	current = stack;
	min = stack->content;
	while (current != NULL)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

int	ft_check_sort(t_stack *list_A)
{
	while (list_A && list_A->next)
	{
		if (list_A->index > list_A->next->index)
			return (0);
		list_A = list_A->next;
	}
	return (1);
}

int	ft_sort_index(t_stack *list_A)
{
	t_stack	*current;
	t_stack	*min_node;
	int		min_value;
	int		index;

	index = 0;
	while (1)
	{
		current = list_A;
		min_node = NULL;
		min_value = __INT_MAX__;
		while (current)
		{
			if (current->index == -1 && current->content < min_value)
			{
				min_value = current->content;
				min_node = current;
			}
			current = current->next;
		}
		if (!min_node)
			return (0);
		min_node->index = index++;
	}
}
