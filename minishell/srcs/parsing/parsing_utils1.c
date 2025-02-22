/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:47:12 by rvikrama          #+#    #+#             */
/*   Updated: 2025/01/16 20:47:13 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*cpy_key(t_mem *m, int j)
{
	char	*new;
	int		len;
	int		mark;
	int		index;

	j++;
	len = 0;
	mark = j;
	index = 0;
	new = NULL;
	while (m->line[j] && is_key_char(m->line[j]) && !spe_case(m->line[j]))
	{
		j++;
		len++;
	}
	if (len >= 1)
	{
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (!new)
			failure(-1, m);
		while (index < len)
			new[index++] = m->line[mark++];
		new[index] = '\0';
	}
	return (new);
}

void	push_file_elem(t_cmd_elem *e, char **buf, bool quotes, enum e_r type)
{
	t_file_elem	*f;
	t_file_elem	*tmp;

	f = (t_file_elem *)malloc(sizeof(t_file_elem));
	if (!f)
		exit(EXIT_FAILURE);
	f->path = *buf;
	f->fd = 0;
	f->next = NULL;
	f->quotes = quotes;
	f->redir_type = type;
	tmp = e->file->first;
	if (!tmp)
		e->file->first = f;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = f;
	}
	return ;
}

int	set_redir_type(char *l, int i, t_cmd_elem *e, t_mem *mem)
{
	if (l[i] == '>' && l[i + 1] != '>' && !is_sep(l[i + 1]) && l[i + 1])
		e->redir_type = R_OUTPUT;
	else if (l[i] == '<' && l[i + 1] != '<' && !is_sep(l[i + 1]) && l[i + 1])
		e->redir_type = R_INPUT;
	else if (l[i] == '>' && l[i + 1] == '>' && l[i + 2])
		e->redir_type = RR_OUTPUT;
	else if (l[i] == '<' && l[i + 1] == '<' && l[i + 2])
		e->redir_type = RR_INPUT;
	else
	{
		e->redir_type = R_NONE;
		push_ret_elem(mem, 2);
		return (-2);
	}
	return (e->redir_type);
}

int	check_cmd(t_cmd *cmd)
{
	t_cmd_elem	*elem;
	t_cmd_elem	*prev;

	elem = cmd->first;
	prev = NULL;
	while (elem)
	{
		if (elem->args_len <= 0 && !elem->file->first)
			return (-1);
		if (prev && (elem->args_len <= 0
				&& !elem->file->first) && prev->is_piped)
			return (-1);
		prev = elem;
		elem = elem->next;
	}
	return (1);
}

void	expansion_split(t_mem *m, int *i, t_cmd_elem *elem, enum e_r *t)
{
	char	*key;
	char	*value;
	int		n;

	n = 0;
	key = cpy_key(m, *i);
	value = find_value_in_env(key, m);
	if (value)
	{
		while (value[n])
		{
			if (value[n] == ' ')
			{
				end_arg(m->buffer, elem, m, t);
				n++;
			}
			else
				*(m->buffer) = copy_in_buffer((*m->buffer), value[n++], m);
		}
	}
	(*i) += ft_strlen(key) + 1;
	free(value);
	free(key);
	return ;
}
