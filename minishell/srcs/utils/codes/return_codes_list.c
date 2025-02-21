/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhewong <zhewong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:41:07 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/10 12:41:08 by zhewong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	return_last_ret(t_mem *mem)
{
	t_ret_elem	*elem;

	elem = mem->ret_list->first;
	if (!elem)
		return (0);
	while (elem->next)
		elem = elem->next;
	if (elem->ret_code)
		return (elem->ret_code);
	return (0);
}

void	push_ret_elem(t_mem *mem, int ret_value)
{
	t_ret_elem	*elem;
	t_ret_elem	*tmp;

	tmp = NULL;
	elem = (t_ret_elem *)malloc(sizeof(t_ret_elem));
	if (!(elem))
		failure(EXIT_FAILURE, mem);
	elem->ret_code = ret_value;
	elem->next = NULL;
	if (!mem->ret_list->first)
		mem->ret_list->first = elem;
	else
	{
		tmp = mem->ret_list->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	return ;
}
