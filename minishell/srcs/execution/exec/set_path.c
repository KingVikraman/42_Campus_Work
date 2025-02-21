/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhewong <zhewong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:40:05 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/07 12:40:06 by zhewong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_path_set(t_mem *mem)
{
	t_cmd_elem	*elem;

	elem = mem->cmd->first;
	if (!find_key_in_env("PATH", mem))
	{
		while (elem)
		{
			elem->path_set = false;
			elem = elem->next;
		}
		return (-1);
	}
	else
	{
		while (elem)
		{
			elem->path_set = true;
			elem = elem->next;
		}
		return (1);
	}
	return (0);
}

void	close_forked(int old_fd, int old_fd0)
{
	dup2(old_fd, 1);
	dup2(old_fd0, 0);
	close(old_fd);
	close(old_fd0);
	return ;
}

void	dup_forked(int *old_fd, int *old_fd0)
{
	*old_fd = dup(1);
	*old_fd0 = dup(0);
	return ;
}
