/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:44:29 by elefonta          #+#    #+#             */
/*   Updated: 2024/04/11 13:24:23 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index;
	static int	bytes_read;
	char		*line;

	buffer_index = 0;
	bytes_read = 0;
	*line = NULL;
	if (bytes_read == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer_index = 0;
	}

	if (bytes_read == 0 || line == NULL)
		return (NULL);

	line = print_line(buffer, &buffer_index, &bytes_read);

    return (line);
}

char	read_char(int fd, )
{
}
void	stock_line(int fd, )
{
}


char	*print_line(char *buffer, int *buffer_index, int *bytes_read)
{
	char	*line;
	int		end_line_index;
	int		i;
	int		line_index;
	int		line_length;

	line = NULL;
	line_index = 0;
	end_line_index = end_line(buffer, *buffer_index, *bytes_read);
	line_length = (end_line_index != -1) ? (end_line_index - buffer_index *1) : (*bytes_read - buffer_index);

	line = malloc((line_length +1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = *buffer_index;
	while (i <= end_line_index)
	{
		line[line_index++] = buffer[i];
		i++;
	}
	line[line_index] = '\0';
	*buffer_index += line_length;
	return (line);

}

int	end_line(char *buffer, int buffer_index, int bytes_read)
{
	int	i ;

	i = buffer_index;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}