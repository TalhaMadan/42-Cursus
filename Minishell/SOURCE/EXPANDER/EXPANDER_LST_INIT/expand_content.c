/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:32:47 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 18:35:48 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

static int	c_index(char *content, int *i, int flag)
{
	while (content[*i] && content[*i] != '$' && content[*i] != D_QUOTES)
	{
		if (flag == 1 && content[*i] == S_QUOTES)
			break ;
		*i += 1;
	}
	return (*i);
}

int	null_check_substr(char *substr, char *joinedstr)
{
	if (!substr)
	{
		(void)joinedstr;
		return (1);
	}
	return (0);
}

char	*straight_expand(t_prime *g_prime, char *c, int *end, int *env)
{
	int		i;
	int		start;
	char	*joinedstr;
	char	*sub;

	joinedstr = ft_strdup("");
	i = *end;
	while (c[i] && !chrchr_quotes(c[i]))
	{
		start = i;
		if (c[i] != '$')
			sub = ft_substr(c, start, c_index(c, &i, 1) - start);
		else
		{
			sub = dollar_control(c, &i, g_prime, env);
			if (sub && !*sub && !*end && !c[i] &&!chrchr_quotes(c[*end + 1]))
				*env = -1;
			if (null_check_substr(sub, joinedstr))
				break ;
		}
		joinedstr = ft_strjoin(joinedstr, sub);
		free(sub);
	}
	*end = i;
	return (joinedstr);
}

char	*d_quotes_expand(t_prime *g_prime, char *content, int *end, int *env)
{
	int		start;
	int		i;
	char	*substr;
	char	*joinedstr;

	joinedstr = ft_strdup("");
	i = *end + 1;
	while (content[i] && content[i] != D_QUOTES)
	{
		start = i;
		if (content[i] != '$')
			substr = ft_substr(content, start, c_index(content, &i, 0) - start);
		else
		{
			substr = dollar_control(content, &i, g_prime, env);
			if (null_check_substr(substr, joinedstr))
				break ;
		}
		joinedstr = ft_strjoin(joinedstr, substr);
		free(substr);
	}
	*end = i;
	if (content[i] != '\0')
		*end = i + 1;
	return (joinedstr);
}

char	*quotes_trim(char *content, int *end, char quotes)
{
	int		i;
	int		start;
	char	*substr;

	i = *end + 1;
	start = i;
	while (content[i] && content[i] != quotes)
		i++;
	substr = ft_substr(content, start, i - start);
	*end = i;
	if (content[i])
		*end = i + 1;
	return (substr);
}
