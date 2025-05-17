/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:23:10 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:23:11 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	open_pipes(t_prime *g_prime)
{
	int	**fd;
	int	i;

	if (g_prime->cmd_count > 1)
	{
		fd = (int **)malloc(sizeof(int *) * (g_prime->cmd_count - 1));
		i = -1;
		while (++i < g_prime->cmd_count - 1)
			fd[i] = malloc(sizeof(int) * 2);
		g_prime->fd = fd;
		i = -1;
		while (++i < g_prime->cmd_count - 1)
			pipe(g_prime->fd[i]);
	}
}

void	wait_all(t_prime *g_prime, int builtin)
{
	t_parser	*parser;
	int			status;

	parser = g_prime->parser;
	while (parser && builtin <= 1)
	{
		waitpid(parser->pid, &status, 0);
		g_prime->exit_code = status / 256;
		if (parser->outfile == 2 || parser->infile == 2)
			g_prime->exit_code = 1;
		parser = parser->next;
	}
	g_signal = 0;
}

void	fd_closer(t_prime *g_prime)
{
	int	i;

	i = -1;
	while (++i < g_prime->cmd_count - 1)
	{
		if (g_prime->fd[i][1])
			close(g_prime->fd[i][1]);
		if (g_prime->fd[i][0])
			close(g_prime->fd[i][0]);
	}
}
