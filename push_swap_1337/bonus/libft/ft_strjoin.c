#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		len;

	if (!s2)
		return (free(s1), NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (
		i < len)
		str[i++] = *s2++;
	str[len] = '\0';
	free(s1);
	return (str);
}