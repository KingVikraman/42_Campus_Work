/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:12:34 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 21:49:04 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* print_status_debug:
*	Prints the philosopher's status in an easier to read,
*	colorful format to help with debugging. For fork-taking
*	statuses, extra information is displayed to show which fork
*	the philosopher has taken.
*/
static void	print_status_debug(t_philo *philo, char *color,
								char *str, t_status status)
{
	if (status == GOT_FORK_1)
		printf("[%10ld]\t%s%03d\t%s\e[0m: fork [%d]\n",
			get_time_in_ms() - philo->table->arrambam,
			color, philo->id + 1, str, philo->fork[0]);
	else if (status == GOT_FORK_2)
		printf("[%10ld]\t%s%03d\t%s\e[0m: fork [%d]\n",
			get_time_in_ms() - philo->table->arrambam,
			color, philo->id + 1, str, philo->fork[1]);
	else
		printf("[%10ld]\t%s%03d\t%s\e[0m\n",
			get_time_in_ms() - philo->table->arrambam,
			color, philo->id + 1, str);
}

/* write_status_debug:
*	Redirects the status writing for debug mode. For this option,
*	the DEBUG_FORMATTING option must be set to 1 in philo.h.
*/
static void	write_status_debug(t_philo *philo, t_status status)
{
	if (status == MARANAM)
		print_status_debug(philo, RED, "died", status);
	else if (status == SAAPIDAVUM)
		print_status_debug(philo, GREEN, "is eating", status);
	else if (status == THONGGAVUM)
		print_status_debug(philo, CYAN, "is sleeping", status);
	else if (status == YOOSIKAVUM)
		print_status_debug(philo, CYAN, "is thinking", status);
	else if (status == GOT_FORK_1)
		print_status_debug(philo, PURPLE, "has taken a fork", status);
	else if (status == GOT_FORK_2)
		print_status_debug(philo, PURPLE, "has taken a fork", status);
}

/* print_status:
*	Prints a philosopher's status in plain text as required by the project
*	subject:
*		timestamp_in_ms X status
*/
static void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_time_in_ms() - philo->table->arrambam,
		philo->id + 1, str);
}

/* write_status:
*	Prints the status of a philosopher as long as the simulation is
*	still active. Locks the write mutex to avoid intertwined messages
*	from different threads.
*
*	If DEBUG_FORMATTING is set to 1 in philo.h, the status will
*	be formatted with colors and extra information to help with debugging.
*	Otherwise the output will be the regular format required by the project
*	subject.
*/
void	write_status(t_philo *philo, bool reaper_report, t_status status)
{
	pthread_mutex_lock(&philo->table->write_lock);
	if (simulation_nindruvitatha(philo->table) == true && reaper_report == false)
	{
		pthread_mutex_unlock(&philo->table->write_lock);
		return ;
	}
	if (DEBUG_FORMATTING == true)
	{
		write_status_debug(philo, status);
		pthread_mutex_unlock(&philo->table->write_lock);
		return ;
	}
	if (status == MARANAM)
		print_status(philo, "died");
	else if (status == SAAPIDAVUM)
		print_status(philo, "is eating");
	else if (status == THONGGAVUM)
		print_status(philo, "is sleeping");
	else if (status == YOOSIKAVUM)
		print_status(philo, "is thinking");
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->table->write_lock);
}

/* write_outcome:
*	Prints the outcome of the simulation if a number of times to
*	eat was specified. Only used for debug purposes.
*/
void	write_outcome(t_table *table)
{
	unsigned int	i;
	unsigned int	full_count;

	full_count = 0;
	i = 0;
	while (i < table->nbr_thiru)
	{
		if (table->thiru[i]->times_ate >= (unsigned int)table->sapidum_ennikai)
			full_count++;
		i++;
	}
	pthread_mutex_lock(&table->write_lock);
	printf("%d/%d philosophers had at least %d meals.\n",
		full_count, table->nbr_thiru, table->sapidum_ennikai);
	pthread_mutex_unlock(&table->write_lock);
	return ;
}
