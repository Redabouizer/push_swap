/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:53:22 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/27 22:12:59 by rbouizer         ###   ########.fr       */
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
