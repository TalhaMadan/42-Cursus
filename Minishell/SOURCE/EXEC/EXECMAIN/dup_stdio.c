/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_stdio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:23:01 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:23:02 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

static void	tempfd_init(t_prime *g_prime, t_parser *parser, int i)
{
	if (g_prime->parser == parser)
		dup2(g_prime->fd[i][1], STDOUT_FILENO);
	else if (!parser->next)
		dup2(g_prime->fd[i - 1][0], STDIN_FILENO);
	else
	{
		dup2(g_prime->fd[i - 1][0], STDIN_FILENO);
		dup2(g_prime->fd[i][1], STDOUT_FILENO);
	}
	fd_closer(g_prime);
}

void	dup_stdio(t_prime *g_prime, t_parser *parser, int i)
{
	int	fd[2];

	signal(SIGINT, interrupt_document);
	if (g_prime->cmd_count > 1 && ourstrcmp(parser->command, "exit"))
		tempfd_init(g_prime, parser, i);
	if (parser->infile == -2)
	{
		pipe(fd);
		write(fd[1], parser->heredoc, ft_strlen(parser->heredoc));
		close (fd[1]);
		if (parser->next || ourstrcmp(parser->command, "echo"))
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	if (parser->outfile >= 2)
		dup2(parser->outfile, STDOUT_FILENO);
	if (parser->infile >= 2)
		dup2(parser->infile, STDIN_FILENO);
}
