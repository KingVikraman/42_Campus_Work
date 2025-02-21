/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhewong <zhewong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:38:48 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/07 12:38:50 by zhewong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_close_pipes(t_mem *mem)
{
	t_cmd_elem	*cmd_elem;

	cmd_elem = mem->cmd->first;
	while (cmd_elem)
	{
		if (cmd_elem->is_piped)
		{
			close(cmd_elem->pipe[0]);
			close(cmd_elem->pipe[1]);
		}
		cmd_elem = cmd_elem->next;
	}
	return (0);
}

int	close_all_fds(t_mem *mem)
{
	t_cmd_elem	*cmd_elem;
	t_file_elem	*file_elem;
	int			ret;

	ret = -1;
	cmd_elem = mem->cmd->first;
	while (cmd_elem)
	{
		file_elem = cmd_elem->file->first;
		while (file_elem)
		{
			close(file_elem->fd);
			file_elem = file_elem->next;
		}
		cmd_elem = cmd_elem->next;
	}
	return (ret);
}
