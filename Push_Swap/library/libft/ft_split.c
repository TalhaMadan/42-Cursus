/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:34:22 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:34:24 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countchar(const char *s, char c, int opt_delimit)
{
	size_t	i;

	i = 0;
	if (opt_delimit)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	else
	{
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static size_t	ft_wordcounter(const char *str, char c)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		wordcount++;
		while (str[i] != '\0' && str[i] == c)
			i++;
	}
	return (wordcount);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	wordcount;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	wordcount = ft_wordcounter(s, c);
	array = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!array)
		return (NULL);
	while (i < wordcount)
	{
		s += ft_countchar(s, c, 0);
		array[i] = ft_substr(s, 0, ft_countchar(s, c, 1));
		if (!array)
			return (NULL);
		s += ft_countchar(s, c, 1) + ft_countchar(s, c, 0);
		i++;
	}
	array[i] = NULL;
	return (array);
}
