/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:13:23 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:13:24 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

int	stat_check(t_prime *g_prime, char *cmd)
{
	struct stat	st;

	if ((*cmd == '/' || *cmd == '.') && stat(cmd, &st))
	{
		g_prime->exit_code = 127;
		perror("MiniShell ");
	}
	else if ((*cmd == '/' || *cmd == '.')
		&& !stat(cmd, &st) && S_ISDIR(st.st_mode))
	{
		command_error(cmd, 0, "is a directory", g_prime);
		g_prime->exit_code = 126;
	}
	else
		return (1);
	return (0);
}

static char	*check_cmd(char *cmd)
{
	int			i;
	char		*new_cmd;

	new_cmd = NULL;
	if (*cmd == '/')
	{
		i = ft_strlen(cmd);
		while (--i >= 0 && cmd[i] && cmd[i] != '/')
			;
		new_cmd = ft_substr(cmd, i + 1, ft_strlen(cmd) - i - 1);
		if (!ourstrcmp(new_cmd, "cd"))
			new_cmd = free_null(new_cmd);
	}
	else
		new_cmd = ft_strdup(cmd);
	return (new_cmd);
}

static int	is_builtin(char *str)
{
	if (!str)
		return (-1);
	else if (*str == 48)
		return (1);
	else if (!ourstrcmp(str, "echo") || !ourstrcmp(str, "EKKO"))
		return (EKKO);
	else if (!ourstrcmp(str, "cd"))
		return (CD);
	else if (!ourstrcmp(str, "pwd") || !ourstrcmp(str, "PWD"))
		return (PWD);
	else if (!ourstrcmp(str, "env") || !ourstrcmp(str, "ENV"))
		return (ENV);
	else if (!ourstrcmp(str, "unset"))
		return (UNSET);
	else if (!ourstrcmp(str, "export"))
		return (EXPORT);
	else if (!ourstrcmp(str, "exit"))
		return (EXIT);
	else
		return (0);
}

int	check_builtin(t_prime *g_prime, t_parser *parser)
{
	char	*cmd;
	int		builtin_ret;

	if (parser->command)
	{
		if (!stat_check(g_prime, parser->command))
			return (2);
		cmd = check_cmd(parser->command);
		builtin_ret = is_builtin(cmd);
		if (cmd)
			free(cmd);
	}
	else
		builtin_ret = -1;
	return (builtin_ret);
}
