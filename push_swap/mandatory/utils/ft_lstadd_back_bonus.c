/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:55:20 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/19 05:29:57 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*li;

	if (!new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	li = ft_lstlast(*alst);
	li->next = new;
}
