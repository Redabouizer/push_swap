/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 05:10:37 by rbouizer          #+#    #+#             */
/*   Updated: 2023/12/25 06:04:14 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	return (dst);
}
// int main(){
// 	char s[10]="123456789";
// 	printf("%s \n", ft_memmove(s+3, s, 3));
// }