/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:46:53 by rvikrama          #+#    #+#             */
/*   Updated: 2025/01/16 20:46:55 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	char	*mem;
	char	ch;
	size_t	i;

	mem = (char *)dest;
	ch = (char)c;
	i = 0;
	while (i < len)
	{
		mem[i] = ch;
		i++;
	}
	return (dest);
}

int	init_parse_struct(t_parse *p, t_mem *m)
{
	p->ret = 1;
	p->r_type = R_NONE;
	p->i = 0;
	p->e = m->cmd->first;
	p->error = false;
	return (0);
}

int	sub_parse_line(t_mem *m, t_parse *p, char *ito)
{
	if (m->line[p->i] == ' ')
	{
		end_arg(m->buffer, p->e, m, &p->r_type);
		p->i++;
	}
	else if (m->line[p->i] == '\'' || m->line[p->i] == '"')
	{
		read_quoted(m, &p->i, p);
		p->i++;
		*(m->buffer) = copy_str_in_buf((*m->buffer), "", m);
	}
	else if (m->line[p->i] == '$' && m->line[p->i + 1]
		&& !(m->line[p->i + 1] == '?')
		&& is_key_char_begin(m->line[p->i + 1]))
		expansion_split(m, &p->i, p->e, &p->r_type);
	else if (m->line[p->i] == '$' && m->line[p->i + 1] == '?')
	{
		p->i += 2;
		ito = ft_itoa(return_last_ret(m), m);
		*(m->buffer) = copy_str_in_buf((*m->buffer), ito, m);
		free(ito);
	}
	else
		return (0);
	return (1);
}

int	parse_line(t_mem *m)
{
	t_parse	p;
	int		ret;

	init_parse_struct(&p, m);
	while (m->line[p.i])
	{
		if (sub_parse_line(m, &p, NULL))
			;
		else if (m->line[p.i] == '|')
			handle_pipe(m, &p);
		else if (is_redir(m->line[p.i]))
			handle_redir(m, &p);
		else if (m->line[(p.i)++])
			(*m->buffer) = copy_in_buffer((*m->buffer), m->line[p.i - 1], m);
		if (p.error)
			return (-1);
	}
	end_arg(m->buffer, p.e, m, &p.r_type);
	if (check_parsing_end_conditions(m, &ret) < 0)
		return (ret);
	return (syntax_error(m));
}
