/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:57:09 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/18 07:54:11 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL; stack_b = NULL; i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (process_tokens(&stack_a, argv[i]) != 0)
				return (free_memory(stack_a), 1);
			i++;
		}
		if (rep_number(stack_a))
			return (free_memory(stack_a), 1);
		ft_sort_index(stack_a);
		ft_sort_node(&stack_a, &stack_b);
	}
	free_memory(stack_a);
	free_memory(stack_b);
	return (0);
}

