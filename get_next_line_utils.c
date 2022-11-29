#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	char			*string;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	string = (char *)malloc(((s1len + s2len) + 1) * (sizeof(char)));
	if (!string)
		return (NULL);
	ft_memcpy(string, s1, s1len);
	ft_memcpy(&string[s1len], s2, s2len);
	string[s1len + s2len] = '\0';
	return (string);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	size_t			i;
	size_t			strlen;

	i = 0;
	if (!s || !len)
		return (ft_strdup("\0"));
	strlen = ft_strlen(s) + 1;
	if (start > strlen)
		return (ft_strdup("\0"));
	if (len > ft_strlen(&(s[start])))
		len = ft_strlen(&(s[start]));
	fresh = (char *)malloc((len + 1) * (sizeof(char)));
	if (!fresh)
		return (NULL);
	while (i < len && s[start + i])
	{
		fresh[i] = s[start + i];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
