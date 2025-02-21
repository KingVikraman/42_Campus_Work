/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:13:13 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:33:09 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	option(char *str)
{
	if (*str++ != '-')
		return (false);
	if (!*str)
		return (false);
	while (*str)
		if (*str++ != 'n')
			return (false);
	return (true);
}

int	echo_args(t_cmd_elem *elem, int start_index)
{
	bool	no_newline;
	int		i;

	no_newline = (start_index > 1);
	i = start_index;
	while (i < elem->args_len && elem->args[i])
	{
		ft_putstr_fd(elem->args[i], 1);
		if (i + 1 < elem->args_len)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!no_newline)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	ft_exec_echo(t_cmd_elem *elem, t_mem *mem)
{
	int	i;

	i = 1;
	if (elem->args_len < 2)
	{
		ft_putstr_fd("\n", 1);
		push_ret_elem(mem, 0);
		return (0);
	}
	while (i < elem->args_len && option(elem->args[i]))
		i++;
	echo_args(elem, i);
	push_ret_elem(mem, 0);
	return (0);
}
