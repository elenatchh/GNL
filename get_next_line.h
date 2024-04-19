/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melondeau <melondeau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:10:03 by elefonta          #+#    #+#             */
/*   Updated: 2024/04/19 18:39:53 by melondeau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

char	*get_next_line(int fd);
char	*ft_r_and_c(char *str,  size_t n, size_t end, char *buffer);
struct  s_stat{
    char    *old_line;
    size_t  full_readed;
    char    *line;
};
char	*get_current_line(struct s_stat *raf, char *buffer, size_t readed);
char	*ft_parse_line(char *buffer, size_t i, size_t readed, struct s_stat *raf);


#endif