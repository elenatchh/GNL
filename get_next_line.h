/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:10:03 by elefonta          #+#    #+#             */
/*   Updated: 2024/04/16 13:23:57 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
ssize_t	ft_read_and_stock(char *stock, int fd);
char	*ft_extract_line(char *stock);
void	ft_shift_stock(char *stock, int n);

#endif