/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:20:11 by ajordan-          #+#    #+#             */
/*   Updated: 2024/11/21 14:11:37 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void ft_handler(int signal, siginfo_t *info, void *context)
{
    (void)context; // Suppress unused parameter warning

    static int bit = 0;
    static int i = 0;
    pid_t client_pid = info->si_pid;

    if (signal == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
        // Send a signal back to the client to indicate readiness for the next bit
        kill(client_pid, SIGUSR1);
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;

    (void)argv;
    if (argc != 1)
    {
        ft_printf("\033[91mError: wrong format.\033[0m\n");
        ft_printf("\033[33mTry: ./server\033[0m\n");
        return (0);
    }
    pid_t pid = getpid();
    ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
    ft_printf("\033[90mWaiting for a message...\033[0m\n");

    sa.sa_sigaction = ft_handler; // Use the correct handler type
    sa.sa_flags = SA_SIGINFO; // Indicate that we want to use the siginfo_t
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
    {
        pause();
    }
    return (0);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                minishell                       