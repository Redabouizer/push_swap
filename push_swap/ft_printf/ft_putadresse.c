/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:37:28 by rbouizer          #+#    #+#             */
/*   Updated: 2024/01/07 16:45:58 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadresse(unsigned long nb)
{
	int		cout;
	char	*base;

	base = "0123456789abcdef";
	cout = 0;
	if (nb >= 16)
	{
		cout += ft_putadresse(nb / 16);
		cout += ft_putadresse(nb % 16);
	}
	else
		cout += ft_putchar(base[nb]);
	return (cout);
}
