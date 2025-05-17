/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:07:48 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 12:07:49 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

int	infile_init(t_expander *expander, t_parser *parser, t_prime *g_prime)
{
	struct stat	st;
	char		*fn;
	int			*fd;

	(void)g_prime;
	fd = &parser->infile;
	if (expander->type == SIGN_SIR)
	{
		fn = expander->next->content;
		if (expander->ex_content)
			fn = expander->ex_content;
		else if (*expander->next->content == '\\')
			fn = expander->next->content + 1;
		if (stat(expander->next->content, &st) != 0)
			file_error(fn, "No such file or directory", fd, g_prime);
		else
			*fd = open(fn, O_RDONLY, 0777);
	}
	if (expander->type == HEREDOC)
		*fd = -2;
	return (*fd);
}
