/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melondeau <melondeau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:09:56 by elefonta          #+#    #+#             */
/*   Updated: 2024/04/19 15:16:55 by melondeau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str, size_t n)
{
	char *tmp;
	int	i;
	
	tmp = malloc(sizeof(char *) * n);
	i=0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++; 
	}
	return (tmp);
}
