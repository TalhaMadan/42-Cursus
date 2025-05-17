/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wspace_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:38:42 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 18:42:20 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

t_list	*wspace_split(char *line, int start, int end, int quotes)
{
	t_list	*lex_slist;

	lex_slist = NULL;
	while (line && line[end])
	{
		start = end;
		if (chrchr_wspace(line[end]))
			while (line[end] && chrchr_wspace(line[end]))
				end++;
		else
		{
			while (line[end] && !chrchr_wspace(line[end]))
			{
				quotes = line[end];
				if (chrchr_quotes(line[end]))
					while (line[++end] && line[end] != quotes)
						;
				end++;
			}
			ft_lstadd_back(&lex_slist, ft_lstnew \
				(ft_substr(line, start, end - start)));
		}
	}
	return (lex_slist);
}
