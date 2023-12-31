/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:38:11 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:38:13 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_checknewline(char *buffer);
char	*ft_newline(char *buffer);
char	*new_buffer(char *buffer);
char	*read_line(int fd, char *buffer);
char	*get_next_line(int fd);
#endif
