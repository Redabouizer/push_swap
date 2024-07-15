/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:58 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/15 20:00:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fixed_sort(t_stack **list_A)
{
	while (ft_check_sort(*list_A) == 0)
		ft_reverse_rotate(list_A, 'a');
}

bool	is_in_upper_half(t_stack *b, int index)
{
	t_stack	*tmp;
	int		size;
	int		i;

	tmp = b;
	i = 0;
	size = ft_lstsize(b);
	while (tmp && i++ < size / 2)
	{
		if (tmp->index == index)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	sort_stack(t_stack **list_A, t_stack **list_B)
{
	int	pivot1;
	int	pivot2;

	pivot2 = 0;
	while (ft_lstsize(*list_A) > 3)
	{
		pivot1 = (ft_lstsize(*list_A) / 6) + pivot2;
		pivot2 += ft_lstsize(*list_A) / 3;
		while (ft_lstsize(*list_B) < pivot2 && ft_lstsize(*list_A) > 3)
		{
			if (*list_B && ((*list_A)->index >= pivot2)
				&& ((*list_B)->index < pivot1))
				ft_rotate_a_b(list_A, list_B);
			else if (*list_B && (*list_B)->index < pivot1)
				ft_rotate(list_B, 'b');
			if ((*list_A)->index >= pivot2)
				ft_rotate(list_A, 'a');
			else if ((*list_A)->index < pivot2)
				ft_push(list_B, list_A, 'b');
		}
	}
}

void	sort_stack_pro(t_stack **list_A, t_stack **list_B)
{
	int	max;

	max = ft_lstlast(*list_A)->index;
	while (ft_lstsize(*list_B) > 0)
	{
		if (*list_B && (*list_A)->index - 1 == (*list_B)->index)
			ft_push(list_A, list_B, 'a');
		else if (*list_B && (*list_A)->index - 1 == ft_lstlast(*list_B)->index)
			(ft_reverse_rotate(list_B, 'b'), ft_push(list_A, list_B, 'a'));
		else if (ft_lstlast(*list_A)->index == max)
			(ft_push(list_A, list_B, 'a'), ft_rotate(list_A, 'a'));
		else if (*list_B && ft_lstlast(*list_A)->index < (*list_B)->index)
			(ft_push(list_A, list_B, true), ft_rotate(list_A, true));
		else if (*list_B
			&& (ft_lstlast(*list_A)->index < ft_lstlast(*list_B)->index))
			(ft_reverse_rotate(list_B, 'b'), ft_push(list_A, list_B, 'a'),
				ft_rotate(list_A, 'a'));
		else if ((*list_A)->index - 1 == ft_lstlast(*list_A)->index)
			ft_reverse_rotate(list_A, 'a');
		else if (*list_B && is_in_upper_half(*list_B, (*list_A)->index - 1))
			ft_rotate(list_B, 'b');
		else
			ft_reverse_rotate(list_B, 'b');
	}
}

void	ft_sort_node(t_stack **list_A, t_stack **list_B)
{
	int	nb;

	if (ft_check_sort(*list_A) == 0)
	{
		nb = ft_lstsize(*list_A);
		if (nb == 2)
			ft_sort2(list_A, 'a');
		else if (nb == 3)
			ft_sort3(list_A, 'a');
		else if (nb == 5)
			ft_sort5(list_A, list_B);
		else
		{
			sort_stack(list_A, list_B);
			ft_sort3(list_A, 'a');
			sort_stack_pro(list_A, list_B);
			ft_fixed_sort(list_A);
		}
	}
}
