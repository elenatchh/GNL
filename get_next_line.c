/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:05:34 by elefonta          #+#    #+#             */
/*   Updated: 2024/04/16 13:25:39 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE];
	char		*line;
	ssize_t		byte_count;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	byte_count = BUFFER_SIZE;
	while (!ft_strchr(stock, '\n') && byte_count == BUFFER_SIZE)
	{
		byte_count = ft_read_and_stock(stock, fd);
		if (byte_count == -1)
			return (NULL);
	}
	line = ft_extract_line(stock);
	if (!line || !*line)
		stock[0] = '\0';
	return (line);
}

ssize_t	ft_read_and_stock(char *stock, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	byte_count;
	ssize_t	i;
	ssize_t	start;

	byte_count = read(fd, buffer, BUFFER_SIZE);
	if (byte_count == -1)
		return (-1);
	buffer[byte_count] = '\0';
	i = 0;
	while (stock[i])
		i++;
	start = i;
	i = 0;
	while (buffer[i])
	{
		stock[start + i] = buffer{i};
		i++;
	}
	return (byte_count);
}

char	*ft_extract_line(char *stock)
{
	char	*line;
	int		i;

	if (!stock)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0 ;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	if (stock[i] == '\n')
		i++;
	ft_shift_stock(stock, i);
	return (line);
}

void	ft_shift_stock(char *stock, int n)
{
	int	i;
	int	j;

	i = 0;
	j = n;
	while (stock[j])
	{
		stock[i] = stock[j];
		i++;
		j++;
	}
	while (i < BUFFER_SIZE)
	{
		stock[i] = '\0';
		i++;
	}
}
