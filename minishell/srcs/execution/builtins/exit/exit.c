/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhewong <zhewong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:24:56 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/03 14:24:58 by zhewong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	sub_ft_atoi(const char *str, bool *big, int i, long sign)
{
	long	result;

	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		if (result > INT_MAX || result < INT_MIN)
		{
			*big = true;
			return (0);
		}
	}
	return ((int)result * sign);
}

int	ft_atoi(const char *str, bool *big)
{
	long	i;
	long	max;
	long	sign;

	i = 0;
	max = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (max >= 1)
			return (0);
		if (str[i] == '-')
			sign = -sign;
		max++;
		i++;
	}
	return (sub_ft_atoi(str, big, i, sign));
}

bool	str_is_all_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
		{
			i++;
			continue ;
		}
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

int	exit_clean(t_cmd_elem *elem, int ret, t_mem *mem)
{
	int	atoi;

	atoi = 0;
	if ((elem->is_piped || mem->exited) && elem->args[1])
	{
		mem->exited = true;
		atoi = ft_atoi(elem->args[1], false);
		push_ret_elem(mem, atoi);
		return (atoi);
	}
	if (elem->args_len == 1 && !(prev_is_piped(elem, mem->cmd)))
		ft_putstr_fd("exit\n", 1);
	push_ret_elem(mem, ret);
	free_mem_no_exit(mem);
	free_mem(mem);
	exit (ret);
	return (1);
}

int	ft_exec_exit(t_cmd_elem *e, t_mem *m)
{
	int		ret;
	bool	big;
	bool	enter;

	ret = 0;
	big = false;
	enter = false;
	if (e)
	{
		if (str_is_all_digit(e->args[1]) == 1 && !m->exited)
		{
			ret = ft_atoi(e->args[1], &big);
			if (!(prev_is_piped(e, m->cmd)))
				ft_putstr_fd("exit\n", 1);
		}
		else if (e->args_len >= 2 && str_is_all_digit(e->args[1]) == 0 && !big)
		{
			d4_err_p_ret(": numeric argument required\n", e->args[1], m, 255);
			ret = 2;
			enter = true;
		}
	}
	if (e && e->args_len > 2 && !enter)
		return (d_err_p_ret("minishell: exit: too many arguments\n", m, 1, 2));
	return (exit_clean(e, ret, m));
}
