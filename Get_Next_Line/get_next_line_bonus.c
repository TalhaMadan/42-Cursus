/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:01:35 by tamadan           #+#    #+#             */
/*   Updated: 2023/06/09 21:31:00 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_moveline(char *string)
{
	int		i;
	char	*s;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char *) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		s[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		s[i] = string[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *string)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(string) - i));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (string[i])
		s[c++] = string[i++];
	s[c] = '\0';
	free(string);
	return (s);
}

char	*ft_read_and_save(int fd, char *string)
{
	int		bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(string))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(string);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	str[fd] = ft_read_and_save(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_moveline(str[fd]);
	str[fd] = ft_save(str[fd]);
	return (line);
}
