#include "get_next_line.h"

void	ft_strdel(void **as)
{
	if (!as)
		return ;
	free(*as);
	*as = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*join_strings(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	char			*string;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	string = (char *)malloc(((s1len + s2len) + 1) * (sizeof(char)));
	if (!string)
		return (0);
	ft_memcpy(string, s1, s1len);
	ft_memcpy(&string[s1len], s2, s2len);
	string[s1len + s2len] = '\0';
	return (string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	return (join_strings(s1, s2));
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	dest = ((char *)malloc(sizeof(char) * (i + 1)));
	if (dest)
	{
		while (s1[j] != '\0')
		{
			dest[j] = s1[j];
			j++;
		}
		dest[j] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
