/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:36:24 by tamadan           #+#    #+#             */
/*   Updated: 2024/05/17 20:36:25 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/cub3D.h"

char	**skip_space_enter(t_proc *proc)
{
	char	**maps;
	int		i;
	int		j;

	i = 0;
	maps = proc->map;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == ' ' || maps[i][j] == '\t' || maps[i][j] == '\n')
				j++;
			else
				return (maps + i);
		}
		i++;
	}
	return (proc->map);
}

int	check_spaces(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '\t' || map[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
