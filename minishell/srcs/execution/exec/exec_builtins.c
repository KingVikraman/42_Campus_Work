/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:39:04 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:39:20 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exec_build(t_cmd_elem *elem, t_mem *mem)
{
	push_ret_elem(mem, 0);
	if (!elem->args || !elem->args[0])
		return (0);
	if (!ft_strcmp(elem->args[0], "cd"))
		return (ft_exec_cd(elem, mem));
	else if (!ft_strcmp(elem->args[0], "echo"))
		return (ft_exec_echo(elem, mem));
	else if (!ft_strcmp(elem->args[0], "unset"))
		return (ft_exec_unset(elem, mem));
	else if (!ft_strcmp(elem->args[0], "export"))
		return (ft_exec_export(elem, mem));
	else if (!ft_strcmp(elem->args[0], "pwd"))
		return (ft_exec_pwd(mem));
	else if (!ft_strcmp(elem->args[0], "env"))
		return (ft_exec_env(mem->env_list, mem));
	else if (!ft_strcmp(elem->args[0], "exit"))
		return (ft_exec_exit(elem, mem));
	return (0);
}
