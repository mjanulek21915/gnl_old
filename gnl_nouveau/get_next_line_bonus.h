/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 08:12:00 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/01 08:12:00 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_buffer
{
	int				init;
	char			buffer[FOPEN_MAX][BUFFER_SIZE + 1];
}					t_buffer;

int					get_next_line(int fd, char **line);
void				gnl_bzero(char *str, int len);
int					gnl_init(t_buffer *buffer);
int					gnl_strlen(char *str);

#endif
