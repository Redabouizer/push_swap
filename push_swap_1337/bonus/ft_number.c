/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:55 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/10 23:45:11 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_memory(t_stack *list)
{
	t_stack	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

int	rep_number(t_stack *Stack_A)
{
	t_stack	*i;
	t_stack	*j;

	i = Stack_A;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->content == j->content)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
