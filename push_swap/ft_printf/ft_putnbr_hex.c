/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:37:38 by rbouizer          #+#    #+#             */
/*   Updated: 2024/01/07 16:46:17 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(long nb, char x, int len)
{
	int		cout;
	char	*base;

	if (x == 'x')
		base = "0123456789abcdef";
	else if (x == 'X')
		base = "0123456789ABCDEF";
	cout = 0;
	if (nb < 0)
	{
		cout += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= len)
	{
		cout += ft_putnbr_hex(nb / len, x, len);
		cout += ft_putnbr_hex(nb % len, x, len);
	}
	else
		cout += ft_putchar(base[nb]);
	return (cout);
}
