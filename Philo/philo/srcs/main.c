/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:50:51 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 23:35:00 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	simulation_thodangavum(t_table *table)
{
	unsigned int	i;

	table->arrambam = get_time_in_ms() + (table->nbr_thiru * 2 * 10);
	i = 0;
	while (i < table->nbr_thiru)
	{
		if (pthread_create(&table->thiru[i]->thread, NULL,
				&thiruvalluvar, table->thiru[i]) != 0)
			return (error_failure(STR_ERR_THREAD, NULL, table));
		i++;
	}
	if (table->nbr_thiru > 1)
	{
		if (pthread_create(&table->dharma_raja, NULL,
				&dharma_raja, table) != 0)
			return (error_failure(STR_ERR_THREAD, NULL, table));
	}
	return (true);
}
/* start_simulation/simulation_thodangavum:
 *	Launches the simulation by creating a grim reaper thread as well as
 *	one thread for each philosopher.
 *	Returns true if the simulation was successfully started, false if there
 *	was an error.
 */

static void	simulation_niruthavum(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nbr_thiru)
	{
		pthread_join(table->thiru[i]->thread, NULL);
		i++;
	}
	if (table->nbr_thiru > 1)
		pthread_join(table->dharma_raja, NULL);
	if (DEBUG_FORMATTING == true && table->sapidum_ennikai != -1)
		write_outcome(table);
	destroy_mutexes(table);
	free_table(table);
}
/* stop_simulation/ simulation_niruthavum:
 *	Waits for all threads to be joined then destroys mutexes and frees
 *	allocated memory.
 */

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (ac - 1 < 4 || ac - 1 > 5)
		return (msg(STR_USAGE, NULL, EXIT_FAILURE));
	if (!is_valid_input(ac, av))
		return (EXIT_FAILURE);
	table = init_table(ac, av, 1);
	if (!table)
		return (EXIT_FAILURE);
	if (!simulation_thodangavum(table))
		return (EXIT_FAILURE);
	simulation_niruthavum(table);
	return (EXIT_SUCCESS);
}

/* Well this main file actually first checks for number of
arguments : if count of arguments is not 4 or 5 and
prints usage message, then what it does is thaty it
validates all the command-line arguments using
is_valid_input(), once it has done that the main will
initialise the simulation table with certain parsed parameters
then it starts the simulations :spawn philosophers threads
and the dharma_raja if it is applicable, once all the threads
had been joined and the process is terminated it will stop the
simulation by joining all the threads, free the resources and
if it is in a debugging mnode, print a summary.*/