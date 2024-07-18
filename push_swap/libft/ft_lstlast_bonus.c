/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:55:28 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/17 01:55:30 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
	}
	return (lst);
}
