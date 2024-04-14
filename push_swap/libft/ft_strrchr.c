/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:21:04 by rbouizer          #+#    #+#             */
/*   Updated: 2023/12/16 23:10:02 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + len));
	while (len >= 0)
	{
		if (s[len] == (char)(c))
		{
			return ((char *)(s + len));
		}
		len--;
	}
	return (NULL);
}
