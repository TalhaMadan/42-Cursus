/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:33:27 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 23:00:34 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

static char	*expand_content(t_prime *g_prime, char *content, int *env)
{
	int		end;
	char	*joinedstr;
	char	*substr;

	joinedstr = ft_strdup("");
	end = 0;
	while (content[end])
	{
		if (content[end] == S_QUOTES)
			substr = quotes_trim(content, &end, S_QUOTES);
		else
		{
			if (content[end] == D_QUOTES)
				substr = d_quotes_expand(g_prime, content, &end, env);
			else
				substr = straight_expand(g_prime, content, &end, env);
			if (null_check_substr(substr, joinedstr))
				break ;
		}
		joinedstr = ft_strjoin(joinedstr, substr);
		free(substr);
	}
	return (joinedstr);
}

static char	*put_straight(char *content)
{
	int		start;
	int		end;
	char	*substr;
	char	*joinedstr;

	end = 0;
	substr = NULL;
	joinedstr = ft_strdup("");
	while (content[end])
	{
		start = end;
		if (!chrchr_quotes(content[end]))
		{
			while (content[end] && !chrchr_quotes(content[end]))
				end++;
			substr = ft_substr(content, start, end - start);
		}
		else
			substr = quotes_trim(content, &end, content[end]);
		joinedstr = ft_strjoin(joinedstr, substr);
		free(substr);
	}
	return (joinedstr);
}

void	expander(t_prime *g_prime)
{
	t_lexer	*temp;
	int		env;

	if (!g_prime->lexer)
		return ;
	temp = g_prime->lexer;
	while (temp)
	{
		env = 0;
		if (!ourstrcmp(temp->content, "~"))
		{
			free(temp->content);
			temp->content = ft_strdup("$HOME");
		}
		if (!ft_strchr(temp->content, '$'))
			expander_add_node(&g_prime->expander, put_straight(temp->content), \
				temp, env);
		else
			expander_add_node(&g_prime->expander, \
				expand_content(g_prime, temp->content, &env), temp, env);
		temp = temp->next;
	}
}
