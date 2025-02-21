/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dharmaraja.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:11:37 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 22:37:41 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* set_sim_stop_flag/ simualtion_nirthapadum_kodi:
 *	Sets the simulation stop flag to true or false. Only the grim
 *	reaper thread can set this flag. If the simulation stop flag is
 *	set to true, that means the simulation has met an end condition.
 */
static void	simulation_nirthapadum_kodi(t_table *table, bool state)
{
	pthread_mutex_lock(&table->sim_stop_lock);
	table->sim_niruthavum = state;
	pthread_mutex_unlock(&table->sim_stop_lock);
}

/* has_simulation_stopped/ simulation_nindruvitatha:
 *	Checks whether the simulation is at an end. The stop flag
 *	is protected by a mutex lock to allow any thread to check
 *	the simulation status without conflict.
 *	Returns true if the simulation stop flag is set to true,
 *	false if the flag is set to false.
 */
bool	simulation_nindruvitatha(t_table *table)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_niruthavum == true)
		r = true;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (r);
}

/* kill_philo/ thiruvai_kollu:
 *	Checks if the philosopher must be killed by comparing the
 *	time since the philosopher's last meal and the time_to_die parameter.
 *	If it is time for the philosopher to die, sets the simulation stop
 *	flag and displays the death status.
 *	Returns true if the philosopher has been killed, false if not.
 */
static bool	thiruvai_kollu(t_philo *philo)
{
	time_t	time;

	time = get_time_in_ms();
	if ((time - philo->khadaisi_unavu) >= philo->table->saagera_neram)
	{
		simulation_nirthapadum_kodi(philo->table, true);
		write_status(philo, true, MARANAM);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (true);
	}
	return (false);
}

/* end_condition_reached/ mudivu_nilai_adaindhathu:
 *	Checks each philosopher to see if one of two end conditions
 *	has been reached. Stops the simulation if a philosopher needs
 *	to be killed, or if every philosopher has eaten enough.
 *	Returns true if an end condition has been reached, false if not.
 */
static bool	mudivu_nilai_adaindhathu(t_table *table)
{
	unsigned int	i;
	bool			all_ate_enough;

	all_ate_enough = true;
	i = 0;
	while (i < table->nbr_thiru)
	{
		pthread_mutex_lock(&table->thiru[i]->meal_time_lock);
		if (thiruvai_kollu(table->thiru[i]))
			return (true);
		if (table->sapidum_ennikai != -1)
			if (table->thiru[i]->times_ate < (unsigned int)
				table->sapidum_ennikai)
				all_ate_enough = false;
		pthread_mutex_unlock(&table->thiru[i]->meal_time_lock);
		i++;
	}
	if (table->sapidum_ennikai != -1 && all_ate_enough == true)
	{
		simulation_nirthapadum_kodi(table, true);
		return (true);
	}
	return (false);
}
/* grim_reaper/ dharma_raja:
 *	The (grim_reaper/dharma_raja) thread's routine.
 *	Checks if a (philosopher/thiruvalluvar) must
 *	be killed and if all philosophers ate enough. If one of those two
 *	end conditions are reached, it stops the simulation.
 */

void	*dharma_raja(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->sapidum_ennikai == 0)
		return (NULL);
	simulation_nirthapadum_kodi(table, false);
	sim_start_delay(table->arrambam);
	while (true)
	{
		if (mudivu_nilai_adaindhathu(table) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
