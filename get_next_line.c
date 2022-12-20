/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:58:12 by lharvey           #+#    #+#             */
/*   Updated: 2022/12/02 16:35:58 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(void **as)
{
	if (!(*as))
		return ;
	free(*as);
	*as = 0;
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

static void	buffer_add(char *buffer, char *array)
{
	char		*swap;

	swap = ft_strjoin(array, buffer);
	free(array);
	array = swap;
}

/*
** line_output finds a defined EOF. Frees memory not needed.
** Returns char_line, or null based on parameters given.
*/

static char	*line_output(char *arr_str, int red_ret)
{
	int	i;
	char			*temp;
	char			*gnl_out;

	i = 0;
	if (!arr_str || !(*arr_str))
		return (NULL);
	while ((arr_str[i]) != '\0' && (arr_str[i]) != '\n' && i <= red_ret)
		i++;
	gnl_out = ft_substr(arr_str, 0, i);
	if (gnl_out != NULL)
	{
		temp = ft_strdup(&(arr_str[i + 1]));
		if (temp == NULL)
		{
			free(gnl_out);
			return (NULL);
		}
	}
	ft_strdel((void **)&arr_str);
	arr_str = temp;
	free(gnl_out);
	return (gnl_out);
}

/*
** Read continues until \n is found for BUFFER_SIZE bytes
** reading into "buffer", upon which it breaks the loop.
** If the array is empty and read is finished, returns NULL
*/

char	*get_next_line(int fd)
{
	static char	*array[1024];
	char		buffer[BUFFER_SIZE + 1];
	int			read_return;

	read_return = 0;
	if (!BUFFER_SIZE || BUFFER_SIZE < 1 || fd < 0 || fd > 1023)
		return (NULL);
	while ((read_return = (read(fd, buffer, BUFFER_SIZE))) > 0)
	{
		buffer[read_return] = '\0';
		if (array[fd] == NULL)
		{
			array[fd] = ft_strdup(buffer);
			if (!(array[fd]))
				return (NULL);
		}
		else
			buffer_add(buffer, array[fd]);
		if (ft_strchr(array[fd], '\n'))
			break ;
	}
	if ((read_return == 0) || (array[fd] == NULL))
		return (NULL);
	if (read_return != -1)
		return (line_output(array[fd], read_return));
	return (NULL);
}
