/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:52:44 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 21:41:18 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* get_time_in_ms:
 *	Gets the current time in miliseconds since the Epoch (1970-01-01 00:00:00).
 *	Returns the time value.
 */
time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/* philo_sleep/ thiru_urrakam:
 *	Pauses the philosopher thread for a certain amount of time in miliseconds.
 *	Periodically checks to see if the simulation has ended during the sleep
 *	time and cuts the sleep short if it has.
 */
void	thiru_urrakam(t_table *table, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < wake_up)
	{
		if (simulation_nindruvitatha(table))
			break ;
		usleep(100);
	}
}

/* sim_start_delay:
 *	Waits for a small delay at the beginning of each threads execution
 *	so that all threads start at the same time with the same start time
 *	reference. This ensures the grim reaper thread is synchronized with
 *	the philosopher threads.
 */
void	sim_start_delay(time_t start_time)
{
	while (get_time_in_ms() < start_time)
		continue ;
}
