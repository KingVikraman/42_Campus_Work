/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhewong <zhewong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:43 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/10 12:58:45 by zhewong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_env_var(t_env_var *v)
{
	v->i = 0;
	v->key = NULL;
	v->j = 0;
	v->value = NULL;
	v->k = 0;
	return ;
}

void	sub_push_env_var(char *key, char *value, t_env_elem *elem, t_mem *mem)
{
	t_env_elem	*temp;

	if (!mem->temp->first)
	{
		elem->next = NULL;
		mem->temp->first = elem;
		free(key);
		free(value);
		return ;
	}
	else
	{
		temp = mem->temp->first;
		if (temp && temp->next)
			while (temp->next)
				temp = temp->next;
	}
	temp->next = elem;
	elem->next = NULL;
	if (key)
		free(key);
	if (value)
		free(value);
	return ;
}

void	push_env_var(char *key, char *value, t_mem *mem)
{
	t_env_elem	*elem;

	elem = (t_env_elem *)malloc(sizeof(t_env_elem));
	if (!elem)
		failure(EXIT_FAILURE, mem);
	if (key)
		elem->key = ft_strdup(key, mem);
	else
		elem->key = NULL;
	if (value)
		elem->value = ft_strdup(value, mem);
	else
		elem->value = NULL;
	elem->display = mem->no_display_temp;
	sub_push_env_var(key, value, elem, mem);
	return ;
}

void	sub_add_env_var(char *str, t_env_var *v, t_mem *mem, bool append)
{
	v->key[v->j] = '\0';
	v->i++;
	v->j++;
	while (str[v->i])
		v->i++;
	if (append)
		v->j++;
	v->value = (char *)malloc(sizeof(char) * (v->i - v->j + 1));
	if (!v->value)
		failure(EXIT_FAILURE, mem);
	while (v->j < v->i)
	{
		v->value[v->k] = str[v->j];
		v->k++;
		v->j++;
	}
	v->value[v->k] = '\0';
	mem->temp = mem->env_list;
	push_env_var(v->key, v->value, mem);
	return ;
}

t_env_elem	*find_key_in_env(char *key, t_mem *mem)
{
	t_env_elem	*tmp;

	if (!key)
		return (NULL);
	tmp = mem->env_list->first;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->key)
		{
			if (ft_strcmp(tmp->key, key) == 0)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (tmp);
}
