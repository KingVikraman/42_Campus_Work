/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhewong <zhewong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:59:19 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/10 12:59:21 by zhewong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	increment_shell_level(t_env_elem *elem, t_mem *mem)
{
	int		new_value;
	int		ret;
	char	*itoa;

	ret = 0;
	new_value = 0;
	if (!ft_strcmp(elem->key, "SHLVL"))
	{
		new_value = ft_atoi(elem->value, false);
		new_value++;
		itoa = ft_itoa(new_value, mem);
		set_value_in_env(elem->key, itoa, mem);
		free(itoa);
		ret = 1;
	}
	return (ret);
}

int	loop_for_shell_level(t_mem *mem)
{
	t_env_elem	*elem;

	elem = mem->env_list->first;
	while (elem && !increment_shell_level(elem, mem))
		elem = elem->next;
	return (1);
}
