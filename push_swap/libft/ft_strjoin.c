/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:40:49 by rbouizer          #+#    #+#             */
/*   Updated: 2023/12/16 23:03:44 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		n;
	int		m;
	int		i;
	int		j;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	i = -1;
	tab = (char *)malloc(m + n + 1);
	if (!tab)
		return (0);
	while (*(s1 + (++i)))
		tab[i] = s1[i];
	j = -1;
	while ((++j) < m)
		tab[i + j] = s2[j];
	tab[i + j] = '\0';
	return (tab);
}
