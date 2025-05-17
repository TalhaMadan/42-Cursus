/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:16:33 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:16:34 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

void	start_unset(t_prime *g_prime)
{
	char	**temp_name;
	int		array_len;

	g_prime->exit_code = 0;
	array_len = parameters_count(g_prime->parser->parameters);
	if (array_len > 1)
	{
		temp_name = g_prime->parser->parameters;
		while (*(++temp_name))
		{
			if (!env_arg_control(g_prime, *temp_name))
			{
				command_error(0, "unset", "not a valid identifier", g_prime);
				continue ;
			}
			else
				remove_env(g_prime, *temp_name);
		}
	}
}

void	remove_env(t_prime *g_prime, char *name)
{
	t_env_l	*env;
	t_env_l	*temp_env;

	env = g_prime->env_l;
	while (env)
	{
		if (!ourstrcmp(env->name, name))
		{
			if (env->content)
				free(env->content);
			free(env->name);
			if (g_prime->env_l == env)
				g_prime->env_l = g_prime->env_l->next;
			else
				temp_env->next = env->next;
			free(env);
			break ;
		}
		temp_env = env;
		env = env->next;
	}
}
