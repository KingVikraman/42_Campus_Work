/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:47:22 by rvikrama          #+#    #+#             */
/*   Updated: 2025/01/16 20:51:41 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_mem	*init_mem(char **envp, bool env_set)
{
	t_mem	*mem;

	mem = (t_mem *)malloc(sizeof(t_mem));
	if (!mem)
		failure(-1, NULL);
	ft_memset(mem, 0, sizeof(t_mem));
	mem->cmd = NULL;
	mem->line = NULL;
	mem->buffer = NULL;
	if (env_set == true)
		mem->env = envp;
	else
		mem->env = NULL;
	mem->line = NULL;
	mem->ret_list = NULL;
	mem->env_test = NULL;
	return (mem);
}

void	define_mem(t_mem *mem, t_cmd *cmd, char *line, char **buffer)
{
	if (!mem)
		return ;
	mem->cmd = cmd;
	mem->buffer = buffer;
	mem->line = line;
	return ;
}

t_cmd	*init_cmd(t_mem *mem)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		failure(-1, mem);
	cmd->first = NULL;
	return (cmd);
}

t_cmd_elem	*init_cmd_elem(t_cmd *cmd, t_mem *mem)
{
	t_cmd_elem	*elem;

	elem = (t_cmd_elem *)malloc(sizeof(t_cmd_elem));
	if (!elem)
		failure(-1, mem);
	ft_memset(elem, 0, sizeof(t_cmd_elem));
	elem->is_piped = false;
	elem->args_len = 0;
	elem->args = NULL;
	elem->next = NULL;
	elem->redir_type = R_NONE;
	elem->file = (t_file_list *)malloc(sizeof(t_file_list));
	if (!elem->file)
		failure(-1, mem);
	elem->file->first = NULL;
	elem->is_piped = false;
	elem->path = NULL;
	cmd->first = elem;
	return (elem);
}
