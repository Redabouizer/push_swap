/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:41:50 by rbouizer          #+#    #+#             */
/*   Updated: 2023/11/26 17:05:57 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cout_digit(long nb)
{
	size_t	cout;

	cout = 0;
	if (nb <= 0)
	{
		nb = -nb;
		cout = 1;
	}
	while (nb != 0)
	{
		nb /= 10;
		cout++;
	}
	return (cout);
}

char	*ft_itoa(int n)
{
	size_t		cout;
	int			i;
	char		*str;
	long int	nb;

	i = 0;
	nb = n;
	cout = cout_digit(nb);
	str = (char *)malloc(sizeof(char) * (cout + 1));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		i++;
	}
	str[cout] = '\0';
	while (cout > (size_t) i)
	{
		str[cout - 1] = nb % 10 + '0';
		nb /= 10;
		cout--;
	}
	return (str);
}
