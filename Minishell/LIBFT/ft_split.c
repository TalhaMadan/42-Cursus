/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:48:22 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 10:48:23 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stringindex(char const *s, char c)
{
	int	a;

	a = 0;
	if (*s)
	{
		while (*s)
		{
			if (*s != c)
			{
				a++;
				while (*s != c && *s)
					s++;
			}
			else
				s++;
		}
	}
	return (a);
}

static char	*newarray(char const *s, char *returnarray, char c, int flag)
{
	int	x;

	x = flag;
	while (s[x] != c && s[x] != 0)
		x++;
	returnarray = ft_substr(s, flag, x - flag);
	return (returnarray);
}

char	**ft_split(char const *s, char c)
{
	char	**splittedstring;
	int		index;
	int		a;
	int		z;

	if (!s)
		return (NULL);
	z = 0;
	a = 0;
	index = stringindex(s, c);
	splittedstring = (char **)malloc(sizeof(char *) * (index + 1));
	if (!splittedstring)
		return ((char **)ft_strdup(""));
	while (a < index)
	{
		while (s[z] == c)
			z++;
		splittedstring[a] = newarray(s, splittedstring[a], c, z);
		z = z + ft_strlen(splittedstring[a]);
		a++;
	}
	splittedstring[a] = 0;
	return (splittedstring);
}
