/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thiruvalluvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:05:03 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 21:48:23 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* eat_sleep_routine/ unavu_mattrum_urakkam_murai:
 *	When a philosopher is ready to eat, he will wait for his fork mutexes to
 *	be unlocked before locking them. Then the philosopher will eat for a certain
 *	amount of time. The time of the last meal is recorded at the beginning of
 *	the meal, not at the end, as per the subject's requirements.
 */
static void	unavu_mattrum_urakkam_murai(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork[0]]);
	write_status(philo, false, GOT_FORK_1);
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork[1]]);
	write_status(philo, false, GOT_FORK_2);
	write_status(philo, false, SAAPIDAVUM);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->khadaisi_unavu = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_time_lock);
	thiru_urrakam(philo->table, philo->table->saapida_neram);
	if (simulation_nindruvitatha(philo->table) == false)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->times_ate += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	write_status(philo, false, THONGGAVUM);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork[0]]);
	thiru_urrakam(philo->table, philo->table->thunggara_neram);
}

/* think_routine/ yocikkira_murai:
 *	Once a philosopher is done sleeping, he will think for a certain
 *	amount of time before starting to eat again.
 *	The time_to_think is calculated depending on how long it has been
 *	since the philosopher's last meal, the time_to_eat and the time_to_die
 *	to determine when the philosopher will be hungry again.
 *	This helps stagger philosopher's eating routines to avoid forks being
 *	needlessly monopolized by one philosopher to the detriment of others.
 */
static void	yocikkira_murai(t_philo *philo, bool silent)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->table->saagera_neram - (get_time_in_ms()
				- philo->khadaisi_unavu) - philo->table->saapida_neram) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && silent == true)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (silent == false)
		write_status(philo, false, YOOSIKAVUM);
	thiru_urrakam(philo->table, time_to_think);
}

/* lone_philo_routine/ thani_thiru_murai:
 *	This routine is invoked when there is only a single philosopher.
 *	A single philosopher only has one fork, and so cannot eat. The
 *	philosopher will pick up that fork, wait as long as time_to_die and die.
 *	This is a separate routine to make sure that the thread does not get
 *	stuck waiting for the second fork in the eat routine.
 */
static void	*thani_thiru_murai(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_locks[philo->fork[0]]);
	write_status(philo, false, GOT_FORK_1);
	thiru_urrakam(philo->table, philo->table->saagera_neram);
	write_status(philo, false, MARANAM);
	pthread_mutex_unlock(&philo->table->fork_locks[philo->fork[0]]);
	return (NULL);
}

/* philosopher/ thiruvalluvar:
 *	The philosopher thread routine. The philosopher must eat, sleep
 *	and think. In order to avoid conflicts between philosopher threads,
 *	philosophers with an even id start by thinking, which delays their
 *	meal time by a small margin. This allows odd-id philosophers to
 *	grab their forks first, avoiding deadlocks.
 */
void	*thiruvalluvar(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->sapidum_ennikai == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->khadaisi_unavu = philo->table->arrambam;
	pthread_mutex_unlock(&philo->meal_time_lock);
	sim_start_delay(philo->table->arrambam);
	if (philo->table->saagera_neram == 0)
		return (NULL);
	if (philo->table->nbr_thiru == 1)
		return (thani_thiru_murai(philo));
	else if (philo->id % 2)
		yocikkira_murai(philo, true);
	while (simulation_nindruvitatha(philo->table) == false)
	{
		unavu_mattrum_urakkam_murai(philo);
		yocikkira_murai(philo, false);
	}
	return (NULL);
}
