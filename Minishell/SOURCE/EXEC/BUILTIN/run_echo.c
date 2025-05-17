/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:24 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:15:42 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

static int	n_control(char *str)
{
	int	i;

	i = -1;
	if (str[++i] == '-')
	{
		if (str[i + 1] != 'n')
			return (0);
		while (str[++i])
			if (str[i] != 'n')
				return (0);
	}
	else
		return (0);
	return (1);
}

void	start_echo(t_prime *g_prime, t_parser *parser)
{
	char	**path;
	int		nl;

	g_prime->exit_code = 0;
	nl = 0;
	path = &parser->parameters[1];
	while (*path && n_control(*path) == 1)
	{
		nl = 1;
		path++;
	}
	while (*path)
	{
		if (*path)
			write(parser->outfile, *path, ft_strlen(*path));
		if (*(++path))
			write(parser->outfile, " ", 1);
	}
	if (!nl)
		write(parser->outfile, "\n", 1);
}
