/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:19:55 by ajordan-          #+#    #+#             */
/*   Updated: 2024/11/21 16:35:32 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_handler(int signal)
{
	// This handler will be used to wait for the server to be ready for the next bit
	if (signal == SIGUSR1)
	{
		// Server is ready for the next bit
	}
}

void	send_bit(pid_t server_pid, int bit)
{
	if (bit)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	send_message(pid_t server_pid, char *message)
{
	for (int j = 0; message[j] != '\0'; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			send_bit(server_pid, (message[j] >> i) & 0x01);
			// Wait for the server to process the bit
			pause();
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <message>\033[0m\n");
		return (0);
	}

	pid_t server_pid = atoi(argv[1]);
	char *message = argv[2];

	// Set up the signal handler for receiving the server's readiness signal
	signal(SIGUSR1, ft_handler);

	send_message(server_pid, message);
	return (0);
}