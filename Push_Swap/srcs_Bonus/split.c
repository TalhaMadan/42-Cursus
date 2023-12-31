/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:38:52 by tamadan           #+#    #+#             */
/*   Updated: 2023/10/24 20:39:49 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_wordcounter(char **str, char c)
{
	int	i;
	int	wordcount;
	int	index;

	index = 1;
	wordcount = 0;
	while (str[index])
	{
		i = 0;
		while (str[index][i] != '\0' && str[index][i] == c)
			i++;
		while (str[index][i] != '\0')
		{
			while (str[index][i] != '\0' && str[index][i] != c)
				i++;
			wordcount++;
			while (str[index][i] != '\0' && str[index][i] == c)
				i++;
		}
		index++;
	}
	return (wordcount);
}

int	ft_take_split(t_list *list, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		list->a[i] = ft_atoi2(split[i], list);
		list->a_len++;
		i++;
	}
	return (i);
}

void	ft_free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
