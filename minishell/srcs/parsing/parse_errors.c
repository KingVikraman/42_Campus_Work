/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:46:40 by rvikrama          #+#    #+#             */
/*   Updated: 2025/01/16 20:50:46 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	syntax_error(t_mem *mem)
{
	t_cmd_elem	*elem;

	if (!mem || !mem->cmd || !mem->cmd->first)
		return (-1);
	elem = mem->cmd->first;
	while (elem)
	{
		if (elem->redir_type != R_NONE && (!elem->file || !elem->file->first
				|| !elem->file->first->path))
		{
			ft_putstr_fd("minishell: syntax error.\n", 2);
			push_ret_elem(mem, 2);
			return (-1);
		}
		elem = elem->next;
	}
	return (0);
}
