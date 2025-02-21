/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:04:24 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 21:54:00 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* intit_forks:
 *	Allocates memory and initializes fork mutexes.
 *	Returns a pointer to the fork mutex array, or NULL if an error occured.
 */
static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nbr_thiru);
	if (!forks)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->nbr_thiru)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, 0));
		i++;
	}
	return (forks);
}

/* assign_forks:
 *	Assigns two fork ids to each philosopher. Even-numbered philosophers
 *	get their fork order switched. This is because the order in which
 *	philosophers take their forks matters.
 *
 *	For example with 3 philos:
 *		Philo #1 (id: 0) will want fork 0 and fork 1
 *		Philo #2 (id: 1) will want fork 1 and fork 2
 *		Philo #3 (id: 2) will want fork 2 and fork 0
 *	If philo #1 takes fork 0, philo #2 takes fork 1 and philo #3 takes fork 2,
 *	there is a deadlock. Each will be waiting for their second fork which is
 *	in use by another philo.
 *
 *	Making even id philos "left-handed" helps:
 *		Philo #1 (id: 0) takes fork 1 and then fork 0
 *		Philo #2 (id: 1) takes fork 1 and then fork 2
 *		Philo #3 (id: 2) takes fork 0 and then fork 2
 *	Now, philo #1 takes fork 1,
		philo #3 takes fork 0 and philo #2 waits patiently.
 *	Fork 2 is free for philo #3 to take,
		so he eats. When he is done philo #1 can
 *	take fork 0 and eat. When he is done,
		philo #2 can finally get fork 1 and eat.
 *	take fork 0 and eat. When he is done,
		philo #2 can finally get fork 1 and eat.
 */

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->nbr_thiru;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nbr_thiru;
		philo->fork[1] = philo->id;
	}
}

/* init_philosophers:
 *	Allocates memory for each philosopher and initializes their values.
 *	Returns a pointer to the array of philosophers or NULL if
 *	initialization failed.
 */
static t_philo	**init_thiruvalluvar(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->nbr_thiru);
	if (!philos)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->nbr_thiru)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (error_null(STR_ERR_MALLOC, NULL, 0));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, 0));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

/* init_global_mutexes:
 *	Initializes mutex locks for forks, writing and the stop simulation
 *	flag.
 *	Returns true if the initalizations were successful, false if
 *	initilization failed.
 */
static bool	init_global_mutexes(t_table *table)
{
	table->fork_locks = init_forks(table);
	if (!table->fork_locks)
		return (false);
	if (pthread_mutex_init(&table->sim_stop_lock, 0) != 0)
		return (error_failure(STR_ERR_MUTEX, NULL, table));
	if (pthread_mutex_init(&table->write_lock, 0) != 0)
		return (error_failure(STR_ERR_MUTEX, NULL, table));
	return (true);
}

/*init_table:
 *	Initializes the "dining table", where all the all teh data
 *	structures are located.
 *	Returns a pointer to the allocated table stuctures, or NULL
 *	if there is a error during the initialization of the table , or
 *	any sort of comlications with the pilos memory.*/

t_table	*init_table(int ac, char **av, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	table->nbr_thiru = integer_atoi(av[i++]);
	table->saagera_neram = integer_atoi(av[i++]);
	table->saapida_neram = integer_atoi(av[i++]);
	table->thunggara_neram = integer_atoi(av[i++]);
	table->sapidum_ennikai = -1;
	if (ac - 1 == 5)
		table->sapidum_ennikai = integer_atoi(av[i++]);
	table->thiru = init_thiruvalluvar(table);
	if (!table->thiru)
		return (NULL);
	if (!init_global_mutexes(table))
		return (NULL);
	table->sim_niruthavum = false;
	return (table);
}
