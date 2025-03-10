/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:09:31 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:37:14 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	check_export_key(t_cmd_elem *elem, t_mem *mem)
{
	int	i;

	i = 1;
	while (elem->args[i])
	{
		if (!check_key(elem->args[i], mem))
			return (false);
		i++;
	}
	return (true);
}

int	len_env_list(t_mem *mem)
{
	int			len;
	t_env_elem	*elem;

	len = 0;
	elem = mem->env_list->first;
	while (elem)
	{
		elem = elem->next;
		len++;
	}
	return (len);
}

t_env_list	*cpy_env_list(t_mem *m)
{
	t_env_list	*cpy;
	t_env_elem	*t;

	cpy = NULL;
	if (len_env_list(m))
	{
		cpy = (t_env_list *)malloc(sizeof(t_env_list));
		if (!cpy)
			failure(-1, m);
		t = m->env_list->first;
		cpy->first = NULL;
		m->temp = cpy;
		while (t)
		{
			m->no_display_temp = t->display;
			push_env_var(ft_strdup(t->key, m), ft_strdup(t->value, m), m);
			t = t->next;
		}
	}
	return (cpy);
}

t_env_list	*bubble_swap_key(t_env_elem *e, t_env_elem *n, t_env_list *cpy)
{
	t_env_elem	tmp;

	tmp.value = e->value;
	tmp.key = e->key;
	e->value = n->value;
	e->key = n->key;
	n->value = tmp.value;
	n->key = tmp.key;
	return (cpy);
}

t_env_list	*bubble_sort(t_env_list *cpy)
{
	t_env_elem	*e;
	t_env_elem	*n;

	e = cpy->first;
	if (!e)
		return (cpy);
	n = e->next;
	while (e && n)
	{
		if (ft_strcmp(e->key, n->key) > 0)
		{
			bubble_swap_key(e, n, cpy);
			e = cpy->first;
			n = e->next;
			continue ;
		}
		e = e->next;
		if (e)
			n = e->next;
	}
	return (cpy);
}
