/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:25:57 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 11:25:58 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

char	*put_oldpwd(t_env_l *env, char *path)
{
	t_env_l	*temp_env;

	temp_env = env;
	while (temp_env)
	{
		if (!ourstrcmp(temp_env->name, path))
			return (temp_env->content);
		temp_env = temp_env->next;
	}
	return (NULL);
}
