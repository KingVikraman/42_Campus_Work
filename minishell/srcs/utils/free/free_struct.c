/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:24:45 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 18:44:21 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_env_list(t_env_list *list)
{
	t_env_elem	*elem;

	if (!list)
		return ;
	while (list->first)
	{
		elem = list->first;
		list->first = elem->next;
		free(elem->key);
		free(elem->value);
		free(elem);
	}
	free(list);
}

void	free_mem_no_exit(t_mem *mem)
{
	if (!mem)
		return ;
	if (mem->cmd)
	{
		free_cmd_no_exit(mem->cmd);
		mem->cmd = NULL;
	}
	if (mem->buffer && *mem->buffer)
		*mem->buffer = NULL;
}

void	free_mem(t_mem *mem)
{
	if (!mem)
		return ;
	free(mem->line);
	if (mem->cmd)
		free_cmd(mem->cmd);
	if (mem->buffer)
	{
		free(*mem->buffer);
		*mem->buffer = NULL;
	}
	if (mem->env_list)
		free_env_list(mem->env_list);
	if (mem->ret_list)
		free_ret_list(mem);
	free(mem);
}
