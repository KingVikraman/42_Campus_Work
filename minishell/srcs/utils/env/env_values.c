/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhewong <zhewong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:59:06 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/10 12:59:08 by zhewong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*find_value_in_env(char *k, t_mem *mem)
{
	t_env_elem	*e;

	if (!k || !mem->env_list || !mem->env_list->first)
		return (NULL);
	e = mem->env_list->first;
	while (e)
	{
		if (e->key && ft_strcmp(k, e->key) == 0)
			return (ft_strdup(e->value, mem));
		e = e->next;
	}
	return (NULL);
}

void	add_env_var(char *str, t_mem *mem, bool display_option, bool append)
{
	t_env_var	v;

	init_env_var(&v);
	while (str[v.i] && str[v.i] != '=' && str[v.i] != '+')
		v.i++;
	if (append == true)
		v.i++;
	v.key = (char *)malloc(sizeof(char) * (v.i + 1));
	if (!v.key)
		failure(EXIT_FAILURE, mem);
	if (append == true)
		v.i--;
	while (v.j < v.i)
	{
		v.key[v.j] = str[v.j];
		v.j++;
	}
	mem->no_display_temp = display_option;
	sub_add_env_var(str, &v, mem, append);
	return ;
}

bool	replace_value_in_env(char *key, char *value, t_mem *mem)
{
	t_env_elem	*e;
	char		*new_value;

	if (!key || !value || !mem->env_list || !mem->env_list->first)
		return (FALSE);
	e = mem->env_list->first;
	while (e)
	{
		if (ft_strcmp(key, e->key) == 0)
		{
			new_value = ft_strdup(value, mem);
			if (!new_value)
				return (FALSE);
			free(e->value);
			e->value = new_value;
			return (TRUE);
		}
		e = e->next;
	}
	return (FALSE);
}

void	set_value_in_env(char *key, char *value, t_mem *mem)
{
	bool		did_replace;
	bool		display_option;
	t_env_elem	*elem;

	display_option = true;
	elem = find_key_in_env(key, mem);
	if (!elem)
		return ;
	did_replace = replace_value_in_env(key, value, mem);
	mem->no_display_temp = display_option;
	mem->temp = mem->env_list;
	if (!did_replace)
		push_env_var(key, value, mem);
	return ;
}

void	init_env_list(t_mem *mem, bool env_set)
{
	int	i;

	mem->env_list = (t_env_list *)malloc(sizeof(t_env_list));
	if (!mem->env_list)
		failure(EXIT_FAILURE, mem);
	mem->env_list->first = NULL;
	i = 0;
	if (env_set)
	{
		while (mem->env[i])
		{
			add_env_var(mem->env[i], mem, true, false);
			i++;
		}
	}
	else
	{
		set_value_in_env(ft_strdup("PWD", mem), getcwd(NULL, 0), mem);
		set_value_in_env(ft_strdup("SHLVL", mem), ft_strdup("1", mem), mem);
		add_key_no_value("OLDPWD", mem);
	}
	return ;
}
