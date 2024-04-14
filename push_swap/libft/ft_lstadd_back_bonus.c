/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:48:48 by rbouizer          #+#    #+#             */
/*   Updated: 2023/12/16 22:49:33 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*li;

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
