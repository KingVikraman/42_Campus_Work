/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:40:56 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:48:21 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_last_return(char *str)
{
	if (!str || ft_strlen(str) != 2)
		return (false);
	return (str[0] == '$' && str[1] == '?' && !str[2]);
}

void	free_ret_list(t_mem *mem)
{
	t_ret_elem	*current;
	t_ret_elem	*next;

	if (!mem->ret_list)
		return ;
	current = mem->ret_list->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(mem->ret_list);
	mem->ret_list = NULL;
}

t_ret_list	*init_ret_list(t_mem *mem)
{
	t_ret_list	*ret_list;

	ret_list = (t_ret_list *)malloc(sizeof(t_ret_list));
	if (!(ret_list))
		exit(EXIT_FAILURE);
	ret_list->first = NULL;
	mem->ret_list = ret_list;
	return (ret_list);
}
