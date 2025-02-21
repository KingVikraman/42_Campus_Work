/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:11:51 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:33:39 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_tab_env(t_env_list *env)
{
	t_env_elem	*e;

	e = env->first;
	while (e)
	{
		if (e->value && e->display)
		{
			ft_putstr_fd(e->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(e->value, 1);
			ft_putstr_fd("\n", 1);
		}
		e = e->next;
	}
}

int	ft_exec_env(t_env_list *env, t_mem *mem)
{
	if (env)
	{
		print_tab_env(env);
		push_ret_elem(mem, 0);
		return (0);
	}
	ft_putstr_fd("_=/usr/bin/env", 1);
	push_ret_elem(mem, 0);
	return (0);
}
