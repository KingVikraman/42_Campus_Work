/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:14:58 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:33:49 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	sub_execute_cd_args(t_cmd_elem *elem, t_mem *mem, char *current_path)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (chdir(elem->args[1]) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(elem->args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		push_ret_elem(mem, 127);
		return (1);
	}
	new_pwd = getcwd(NULL, 0);
	replace_value_in_env("OLDPWD", current_path, mem);
	replace_value_in_env("PWD", new_pwd, mem);
	push_ret_elem(mem, 0);
	free(new_pwd);
	return (0);
}

int	execute_cd_args(t_cmd_elem *elem, t_mem *mem, char *current_path)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (elem->args_len > 2)
		return (d_err_p_ret("minishell: cd: too many arguments\n", mem, 1, 2));
	if (elem->args[1][0] != '-')
		return (sub_execute_cd_args(elem, mem, current_path));
	new_pwd = find_value_in_env("OLDPWD", mem);
	replace_value_in_env("PWD", new_pwd, mem);
	replace_value_in_env("OLDPWD", current_path, mem);
	chdir(new_pwd);
	push_ret_elem(mem, 0);
	return (0);
}

int	execute_cd_no_arg(t_mem *mem)
{
	char	*home;
	char	*current_wd;

	home = find_value_in_env("HOME", mem);
	current_wd = getcwd(NULL, 0);
	chdir(home);
	set_value_in_env("PWD", home, mem);
	set_value_in_env("OLDPWD", current_wd, mem);
	free(home);
	free(current_wd);
	push_ret_elem(mem, 0);
	return (0);
}

int	ft_exec_cd(t_cmd_elem *elem, t_mem *mem)
{
	char	*current_path;
	int		ret;

	current_path = getcwd(NULL, 0);
	if (elem->args_len == 1)
		ret = execute_cd_no_arg(mem);
	else
		ret = execute_cd_args(elem, mem, current_path);
	free(current_path);
	return (ret);
}
