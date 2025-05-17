/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:23:20 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:23:21 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	executer(t_prime *g_prime, int i)
{
	t_parser	*parser;
	int			builtin;

	if (!g_prime->parser)
		return ;
	open_pipes(g_prime);
	parser = g_prime->parser;
	while (parser && ++i)
	{
		builtin = check_builtin(g_prime, parser);
		if (builtin > 2 && g_prime->cmd_count == 1)
			start_builtin(g_prime, parser, builtin, i - 1);
		else if ((g_prime->cmd_count > 1 || builtin < 2) && parser->command)
		{
			g_signal = 2;
			parser->pid = fork();
			if (!parser->pid)
				start_execve(g_prime, parser, i - 1, builtin);
			builtin = 0;
		}
		parser = parser->next;
	}
	fd_closer(g_prime);
	wait_all(g_prime, builtin);
}
