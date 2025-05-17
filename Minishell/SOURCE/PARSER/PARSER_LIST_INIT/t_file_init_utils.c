/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamadan <tamadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:08:20 by tamadan           #+#    #+#             */
/*   Updated: 2024/01/10 12:08:21 by tamadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIBRARIES/minishell.h"

static t_files	*files_listnew(char *name, int type, int fd)
{
	t_files	*new;

	new = (t_files *)malloc(sizeof(t_files));
	if (!new)
		return (0);
	new->filename = name;
	new->re_type = type;
	new->fd = fd;
	new->next = 0;
	return (new);
}

static t_files	*files_lstlast(t_files *lst)
{
	t_files	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

static void	files_lstadd_back(t_files **lst, t_files *new)
{
	if (new)
	{
		if (!(*lst))
		{
			*lst = new;
			return ;
		}
		files_lstlast(*lst)->next = new;
		new->next = 0;
	}
}

void	files_add_node(t_files **files, char *name, int type, int fd)
{
	files_lstadd_back(files, files_listnew(name, type, fd));
}
