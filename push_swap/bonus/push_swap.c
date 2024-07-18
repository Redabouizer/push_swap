/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:55:05 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/18 08:04:09 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
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
		if (!ft_check(&stack_a, &stack_b) && ft_check_sort(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (free_memory(stack_a), free_memory(stack_b), 0);
}