/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:02:58 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 12:02:59 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

int	chrchr_quotes(char c)
{
	return (c == D_QUOTES || c == S_QUOTES);
}

int	strchr_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (chrchr_quotes(str[i]))
			return (1);
	}
	return (0);
}
