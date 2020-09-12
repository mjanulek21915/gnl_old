/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 08:12:00 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/01 08:12:00 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				gnl_bzero(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}

int					gnl_init(t_buffer *buffer)
{
	int i;
	int j;

	i = 0;
	while (i < FOPEN_MAX)
	{
		j = 0;
		gnl_bzero(((buffer->buffer)[i]), BUFFER_SIZE + 1);
		while (j < BUFFER_SIZE)
		{
			(buffer->buffer)[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int					gnl_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
