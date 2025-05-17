/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmmnd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:23:28 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:23:29 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	start_execve(t_prime *g_prime, t_parser *parser, int i, int builtin)
{
	char	**env_list;
	char	*command;

	command = NULL;
	env_list = NULL;
	dup_stdio(g_prime, parser, i);
	if (builtin > 2 || builtin < 0)
	{
		start_builtin(g_prime, parser, builtin, i);
		exit (0);
	}
	env_list = put_env_copy(g_prime);
	command = put_command(g_prime, parser);
	if (!search_path(g_prime->env_l, "PATH") && builtin == 0)
	{
		if (access(parser->command, F_OK))
		{
			command_error(0, parser->command, \
				"No such file or directory", g_prime);
			exit (127);
		}
	}
	execve(command, parser->parameters, env_list);
	command_error(0, parser->command, "command not found!", g_prime);
	exit(127);
}

void	start_builtin(t_prime *g_prime, t_parser *parser, int built_type, int i)
{
	(void)i;
	if (built_type == EKKO)
		start_echo(g_prime, parser);
	else if (built_type == CD)
		start_cd(g_prime);
	else if (built_type == PWD)
		start_pwd(g_prime, parser);
	else if (built_type == EXPORT)
		start_export(g_prime, parser);
	else if (built_type == UNSET)
		start_unset(g_prime);
	else if (built_type == ENV)
		start_env(g_prime, parser);
	else if (built_type == EXIT)
		start_exit(g_prime, parser);
}
