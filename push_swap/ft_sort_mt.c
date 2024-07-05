/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:58 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/06 00:35:00 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(t_stack **list_A, char c)
{
	ft_swap(list_A, c);
}

void	ft_sort3(t_stack **list_A, char ch)
{
	int	a;
	int	b;
	int	c;

	if (ft_check_sort(*list_A) == 0)
	{
		a = (*list_A)->index;
		b = (*list_A)->next->index;
		c = (*list_A)->next->next->index;
		if (a > b && b > c)
			(ft_swap(list_A, ch), ft_reverse_rotate(list_A, ch));
		else if (a > c && c > b)
			ft_rotate(list_A, ch);
		else if (a > b && c > a)
			ft_swap(list_A, ch);
		else if (b > a && a > c)
		{
			(ft_swap(list_A, ch), ft_rotate(list_A, ch),
				ft_swap(list_A, ch));
		}
		else if (b > c && c > a)
			(ft_reverse_rotate(list_A, ch), ft_swap(list_A, ch));
		else if (c > a && a > b)
			ft_reverse_rotate(list_A, ch);
	}
}

void	ft_sort5(t_stack **list_A, t_stack **list_B)
{
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if ((*list_A)->index < 2)
		{
			ft_push(list_B, list_A, 'b');
			pushed++;
		}
		else
			ft_rotate(list_A, 'a');
	}
	ft_sort3(list_A, 'a');
	if (ft_check_sort(*list_B) == 1)
		ft_sort2(list_B, 'b');
	while (*list_B)
		ft_push(list_A, list_B, 'a');
}
