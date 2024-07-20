/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:56:25 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/19 05:24:57 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_atoi(const char *str)
{
	int		s;
	long	r;
	int		i;

	s = 1;
	i = 0;
	r = 0;
	while (str[i] && ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13))))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			s *= -1;
		i++;
	}
	while ((*(str + i) >= '0' && *(str + i) <= '9') && *(str + i))
	{
		r = r * 10 + str[i] - '0';
		if ((r > 2147483647 && s == 1) || (r < -2147483648 && s == -1))
			return (2147483648);
		i++;
	}
	return ((s * r));
}
