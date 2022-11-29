

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_jstrcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_jstrcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh;
	unsigned int	strlens;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	strlens = (ft_strlen(s1)) + (ft_strlen(s2));
	fresh = (char *)malloc((strlens + 1) * (sizeof(char)));
	if (!fresh)
		return (0);
	ft_jstrcpy(fresh, s1);
	ft_jstrcat(fresh, s2);
	return (fresh);
}

/*
** Overlap-safe way to add new data to the existing data.
*/

void	buffer_add(char *buffer, char **array)
{
	char		*swap;

	swap = ft_strjoin(*array, buffer);
	free(*array);
	*array = swap;
}

/*
** line_output finds a defined EOF. Frees memory not needed.
** Returns value based on **line output.
*/

int		line_output(char **string, char **line)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	if (!string || !line)
		return (-1);
	while ((*string)[i] != '\0' && (*string)[i] != '\n')
		i++;
	if ((*string)[i] == '\n')
	{
		*line = ft_strsub(*string, 0, i);
		temp = ft_strdup(&((*string)[i + 1]));
		ft_strdel(string);
		*string = temp;
		if ((*string)[0] == '\0')
			ft_strdel(string);
	}
	else
	{
		*line = ft_strdup(*string);
		ft_strdel(string);
	}
	return (1);
}