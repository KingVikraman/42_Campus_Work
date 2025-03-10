/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:03:49 by zhewong           #+#    #+#             */
/*   Updated: 2025/01/16 20:49:07 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_sig	g_sig_var;

void	ft_add_history(char *line)
{
	if (line && *line)
		add_history(line);
	return ;
}

bool	loop_readline(char *line, t_mem *mem, char *buffer, t_cmd *cmd)
{
	while (true)
	{
		cmd = init_cmd(mem);
		init_cmd_elem(cmd, mem);
		buffer = NULL;
		s_init(mem);
		line = readline("\033[1;36muser@minishell$ \033[0m");
		define_mem(mem, cmd, line, &buffer);
		if (line)
		{
			if (parse_line(mem) >= 0)
				ft_execution(mem);
			else if (buffer)
				free(buffer);
			ft_add_history(line);
			free_mem_no_exit(mem);
			free(line);
			continue ;
		}
		ft_putstr_fd("exit\n", 1);
		free_mem_no_exit(mem);
		free_mem(mem);
		exit (EXIT_SUCCESS);
	}
	return (true);
}

int	ft_read(char **envp, bool env_set)
{
	char	*line;
	t_mem	*mem;
	char	*buffer;
	t_cmd	*cmd;

	buffer = NULL;
	cmd = NULL;
	mem = init_mem(envp, env_set);
	line = NULL;
	init_env_list(mem, env_set);
	loop_for_shell_level(mem);
	init_ret_list(mem);
	push_ret_elem(mem, 0);
	return (loop_readline(line, mem, buffer, cmd));
}

int	main(int argc, char **argv, char **env)
{
	bool	env_set;

	(void)argv;
	env_set = true;
	if (!*env)
		env_set = false;
	if (argc == 1)
	{
		signal(SIGINT, &s_int);
		signal(SIGQUIT, &s_quit);
		ft_read(env, env_set);
	}
	exit(EXIT_SUCCESS);
}

void	failure(int error, t_mem *mem)
{
	free_mem_no_exit(mem);
	free_mem(mem);
	ft_putstr_fd(SYS_MALLOC, 2);
	exit(error);
}
