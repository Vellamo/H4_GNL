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