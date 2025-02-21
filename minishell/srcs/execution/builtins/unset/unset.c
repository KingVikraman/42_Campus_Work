/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:28:15 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:32:45 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	remove_from_list(t_env_elem *elem, t_mem *mem)
{
	t_env_elem	**indirect;

	indirect = &mem->env_list->first;
	while (*indirect && *indirect != elem)
		indirect = &(*indirect)->next;
	if (*indirect == elem)
	{
		*indirect = elem->next;
		if (elem->key)
			free(elem->key);
		if (elem->value)
			free(elem->value);
		free(elem);
	}
	return (0);
}

int	ft_exec_unset(t_cmd_elem *elem, t_mem *mem)
{
	int			i;
	t_env_elem	*tmp;

	i = 1;
	if (elem->args_len >= 2)
	{
		while (i < elem->args_len)
		{
			tmp = find_key_in_env(elem->args[i], mem);
			if (tmp)
				remove_from_list(tmp, mem);
			i++;
		}
	}
	push_ret_elem(mem, 0);
	return (0);
}
