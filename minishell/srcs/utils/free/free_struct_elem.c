/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:25:44 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 18:39:14 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_file_list(t_file_list *file)
{
	t_file_elem	*elem;
	t_file_elem	*tmp;

	if (!file)
		return ;
	elem = file->first;
	while (elem)
	{
		tmp = elem->next;
		free(elem->path);
		free(elem);
		elem = tmp;
	}
	free(file);
}

void	free_file_list_no_exit(t_file_list *file)
{
	t_file_elem	*elem;
	t_file_elem	*tmp;

	if (!file)
		return ;
	elem = file->first;
	tmp = elem;
	while (tmp)
	{
		tmp = elem->next;
		if (elem->path)
		{
			free(elem->path);
			elem->path = NULL;
		}
		if (elem)
		{
			free(elem);
			elem = NULL;
		}
		elem = tmp;
	}
	free(file);
	return ;
}

void	free_cmd_no_exit(t_cmd *cmd)
{
	t_cmd_elem	*elem;
	t_cmd_elem	*tmp;

	elem = cmd->first;
	tmp = elem;
	while (tmp)
	{
		if (elem->file)
			free_file_list_no_exit(elem->file);
		tmp = elem->next;
		free_tab(elem->args);
		if (elem->path != 0)
			free(elem->path);
		free(elem);
		elem = NULL;
		elem = tmp;
	}
	if (cmd)
		free(cmd);
	cmd = NULL;
	return ;
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd_elem	*elem;
	t_cmd_elem	*tmp;

	if (!cmd)
		return ;
	elem = cmd->first;
	while (elem)
	{
		tmp = elem->next;
		if (elem->file)
			free_file_list(elem->file);
		free_tab(elem->args);
		free(elem);
		elem = tmp;
	}
	free(cmd);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
