/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:58:12 by lharvey           #+#    #+#             */
/*   Updated: 2022/11/29 13:58:46 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Read continues until \n is found, upon which it breaks the loop.
** If the array is empty and read is finished, returns 0
*/

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	dest = ((char *)malloc(sizeof(*s1) * (i + 1)));
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
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)(s));
		else
			s++;
	}
	if ((char)c == '\0' && *s == '\0')
		return ((char *)(s));
	else
		return (0);
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

void	ft_strdel(void **as)
{
	if (!as)
		return ;
	free(*as);
	*as = 0;
}

char	*get_next_line(int fd)
{
	static char	*array[BUFFER_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	char		**line;
	int			read_return;

	read_return = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((read_return = (read(fd, buffer, BUFFER_SIZE))) > 0)
	{
		buffer[read_return] = '\0';
		if (array[fd] == NULL)
		{
			if (!(array[fd] = ft_strdup(buffer)))
				return (-1);
		}
		else
			buffer_add(buffer, &(array[fd]));
		if (ft_strchr(array[fd], '\n'))
			break ;
	}
	if ((read_return == 0) && (array[fd] == NULL))
		return (0);
	if (read_return != -1)
		read_return = line_output(&(array[fd]), line);
	return (read_return);
}
