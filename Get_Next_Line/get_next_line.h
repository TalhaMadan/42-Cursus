/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:02:19 by tamadan           #+#    #+#             */
/*   Updated: 2023/06/09 21:41:19 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_moveline(char *string);
char	*ft_save(char *string);
char	*ft_read_and_save(int fd, char *string);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str);
size_t	ft_strlen(const char *str);
#endif
