/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:38:16 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:38:18 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *buffer)
{
	char	*buf;
	int		rdbyte;

	rdbyte = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_checknewline(buffer) && rdbyte != 0)
	{
		rdbyte = read(fd, buf, BUFFER_SIZE);
		if (rdbyte == -1)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buf[rdbyte] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*b_buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	b_buffer[fd] = read_line(fd, b_buffer[fd]);
	if (b_buffer[fd] == NULL)
		return (NULL);
	line = ft_newline(b_buffer[fd]);
	b_buffer[fd] = new_buffer(b_buffer[fd]);
	return (line);
}
