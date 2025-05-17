/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:16:05 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:16:06 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

static int	is_all_numeric(char *text)
{
	while (text && *text)
	{
		if (*text == '-' || *text == '+')
			text++;
		if (!ft_isdigit(*text))
			return (0);
		text++;
	}
	return (1);
}

void	start_exit(t_prime *g_prime, t_parser *parser)
{
	int	array_len;

	g_prime->exit_code = 0;
	if (g_prime->cmd_count == 1)
		printf("exit\n");
	array_len = parameters_count(&parser->parameters[1]);
	if (parser->parameters[1] && is_all_numeric(parser->parameters[1]))
	{
		g_prime->exit_code = ft_atoi(parser->parameters[1]) % 256;
		if (parser->parameters[1][0] == '-')
			g_prime->exit_code = 256 - (-1 * g_prime->exit_code);
		if (array_len > 1)
		{
			command_error(0, "exit", "too many arguments", g_prime);
			return ;
		}
	}
	else if (parser->parameters[1] && !is_all_numeric(parser->parameters[1]))
	{
		command_error(parser->parameters[1], "exit", \
			"numeric argument required", g_prime);
		g_prime->exit_code = 255;
	}
	exit(g_prime->exit_code);
}
