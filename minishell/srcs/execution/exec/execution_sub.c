/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:39:41 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:38:43 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exec_process(t_cmd_elem *elem, t_mem *mem)
{
	int	ret;

	ret = 0;
	if (!find_key_in_env("PATH", mem) || elem->path)
	{
		if (!is_file(elem->path))
			return (d3_err(": Is a directory\n", elem->args[0], mem, 126));
		if (!mem->found || access(elem->path, F_OK | X_OK) == 0)
		{
			mem->env_test = ft_env_string_tab(mem->env_list, mem);
			if (!find_key_in_env("PATH", mem))
				ret = execve(elem->args[0], elem->args, mem->env_test);
			else
				ret = execve(elem->path, elem->args, mem->env_test);
		}
		else
			return (d3_err(": Permission denied\n", elem->args[0], mem, 126));
	}
	return (ret);
}

int	last_file_fd(t_cmd_elem *elem)
{
	t_file_elem	*tmp;

	tmp = elem->file->first;
	if (!tmp)
		return (-1);
	if (tmp->next == NULL)
		return (tmp->fd);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->fd);
}

void	setup_file_dup(t_cmd_elem *elem)
{
	int	fd_to_pipe;

	if (elem->redir_type == R_OUTPUT || elem->redir_type == RR_OUTPUT)
	{
		fd_to_pipe = last_file_fd(elem);
		dup2(fd_to_pipe, 1);
	}
	else if (elem->redir_type == R_INPUT)
	{
		fd_to_pipe = last_file_fd(elem);
		if (!elem->is_builtin && fd_to_pipe >= 0)
			dup2(fd_to_pipe, 0);
	}
	else if (elem->redir_type == RR_INPUT)
	{
		fd_to_pipe = last_file_fd(elem);
		if (!elem->is_builtin && fd_to_pipe >= 0)
			dup2(fd_to_pipe, 0);
	}
	return ;
}

void	child_function(t_cmd_elem *elem, t_mem *mem, t_cmd_elem *prev_piped)
{
	int	old_fd;
	int	old_fd0;

	if (!elem->is_forked)
		dup_forked(&old_fd, &old_fd0);
	if (elem->is_piped)
		dup2(elem->pipe[1], 1);
	if (prev_piped && !elem->is_builtin)
		dup2(prev_piped->pipe[0], 0);
	setup_file_dup(elem);
	if (elem->is_piped || prev_piped)
		close(elem->pipe[0]);
	if (elem->is_builtin)
		exec_build(elem, mem);
	else if (elem->args)
		exec_process(elem, mem);
	if ((prev_piped || elem->is_piped) || (!elem->is_builtin && elem->path))
	{
		close(old_fd);
		exit(EXIT_FAILURE);
	}
	if (!elem->is_forked)
		close_forked(old_fd, old_fd0);
	return ;
}

bool	setup_builtin_pipe(t_cmd_elem *elem, t_mem *mem, t_cmd_elem **prevPiped)
{
	if (!elem->args || is_builtin(elem->args[0]))
		elem->is_builtin = true;
	else
		elem->is_builtin = false;
	*prevPiped = prev_is_piped(elem, mem->cmd);
	if (*prevPiped || elem->is_piped)
	{
		pipe(elem->pipe);
		return (true);
	}
	return (false);
}
