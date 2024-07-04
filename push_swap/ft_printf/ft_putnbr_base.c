/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:34:57 by rbouizer          #+#    #+#             */
/*   Updated: 2024/06/21 16:44:17 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nb, char *base, int len)
{
	int	cout;

	cout = 0;
	if (nb < 0)
	{
		cout += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= len)
	{
		cout += ft_putnbr_base(nb / len, base, len);
		cout += ft_putnbr_base(nb % len, base, len);
	}
	else
	{
		cout += ft_putchar(base[nb]);
	}
	return (cout);
}
