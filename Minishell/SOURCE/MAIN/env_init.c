/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:03:49 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 12:03:50 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LIBRARIES/minishell.h"

t_env_l	*env_listnew(char *name, char *content)
{
	t_env_l	*new;

	new = (t_env_l *)malloc(sizeof(t_env_l));
	if (!new)
		return (0);
	new->name = name;
	new->content = content;
	new->next = 0;
	return (new);
}

static t_env_l	*env_lstlast(t_env_l	*lst)
{
	t_env_l	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	env_lstadd_back(t_env_l	**lst, t_env_l	*new)
{
	if (new)
	{
		if (!(*lst))
		{
			*lst = new;
			return ;
		}
		env_lstlast(*lst)->next = new;
		new->next = 0;
	}
}

void	path_init(t_prime *g_prime)
{
	t_env_l	*env_l;
	int		i;
	char	**temp_command;
	char	*join;

	env_l = g_prime->env_l;
	g_prime->path = NULL;
	if (!search_path(env_l, "PATH"))
		return ;
	while (env_l)
	{
		if (!ourstrcmp(env_l->name, "PATH"))
			break ;
		env_l = env_l->next;
	}
	temp_command = ft_split(env_l->content, ':');
	i = -1;
	while (temp_command[++i])
	{
		join = ft_strjoin(temp_command[i], "/");
		g_prime->path = dynamic_malloc(g_prime->path, join);
		free(join);
	}
	free(temp_command);
}

void	env_init(t_prime *g_prime, char **env)
{
	int		i;
	int		start;
	int		end;
	char	*name;
	char	*content;

	i = -1;
	while (env && env[++i])
	{
		end = 0;
		while (env[i][end])
		{
			start = end;
			while (env[i][end] && env[i][end] != '=')
				end++;
			name = ft_substr(env[i], start, end);
			end++;
			start = end;
			while (env[i][end])
				end++;
			content = ft_substr(env[i], start, end);
			env_lstadd_back(&g_prime->env_l, env_listnew(name, content));
		}
	}
	path_init(g_prime);
}
