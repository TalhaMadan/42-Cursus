/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:32:39 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:32:40 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

int	ret_null(char c)
{
	return ((c >= '1' && c <= '9') || c == '*' || c == '@' || c == '!');
}

int	put_directly(char c, int *i)
{
	if (c == '%' || c == '+' || c == ',' || c == '.' || c == '/'
		|| c == ':' || c == '=' || c == ']' || c == '^' || c == '}'
		|| c == '~' || c == ' ')
	{
		*i += 1;
		return (1);
	}
	if (c == '\0' || chrchr_quotes(c))
		return (1);
	return (0);
}

int	put_syntxerror(char c)
{
	return (c == '(' || c == '[' || c == 92 || c == '{' || c == ')'
		|| c == ';' || c == '#' || c == '-');
}

int	spcl_chars(char c)
{
	return (c == '0' || c == '?');
}
