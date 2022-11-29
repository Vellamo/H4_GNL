/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:58:12 by lharvey           #+#    #+#             */
/*   Updated: 2022/11/29 16:47:39 by lharvey          ###   ########.fr       */
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
