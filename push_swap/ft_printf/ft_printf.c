/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:37:12 by rbouizer          #+#    #+#             */
/*   Updated: 2024/01/07 17:07:05 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char format, va_list list)
{
	if (format == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (format == 'd' || (format == 'i'))
		return (ft_putnbr_hex(va_arg(list, int), 'x', 10));
	else if (format == 'u')
		return (ft_putnbr_hex(va_arg(list, unsigned int), 'x', 10));
	else if (format == 'x')
		return (ft_putnbr_hex((long)va_arg(list, unsigned int), 'x', 16));
	else if (format == 'X')
		return (ft_putnbr_hex((long)va_arg(list, unsigned int), 'X', 16));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'p')
	{
		ft_putstr("0x");
		return (ft_putadresse((unsigned long)va_arg(list, void *)) + 2);
	}
	else
		return (ft_putchar(format));
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (write(1, "", 0) < 0)
		return (-1);
	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ')
				i++;
			count += check_format(format[i], list);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
