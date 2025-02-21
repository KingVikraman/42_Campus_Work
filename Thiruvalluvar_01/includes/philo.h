/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:29:44 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 18:03:41 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*************************/
/*		LIBRARY				*/
/*************************/

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/****************************/
/*			MACROS			*/
/****************************/

# define MAX_PHILOS 250
# define STR_MAX_PHILOS "250"

# ifndef DEBUG_FORMATTING
#  define DEBUG_FORMATTING 0
# endif

# define RED "\033[31m"
# define GREEN "\033[32m"
# define NC "\033[0m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"

# define STR_PROG_NAME "thiru:"
# define STR_USAGE	"%s usage: ./thiru <number of thiruvalluvars>\
<saagera_neram> <saapida_neram> <thunggara_neram> \
[number_of_times_each_thiruvalluvar_must_eat]\n"
# define STR_ERR_INPUT_DIGIT	"%s invalid input: %s: \
not a valid unsinged integer between 0 and 2147483647.\n"
# define STR_ERR_INPUT_POFLOW	"%s invalid input: \
they must be between 1 and %s thiruvalluvars.\n"
# define STR_ERR_THREAD "%s error: could not create thread. \n"
# define STR_ERR_MALLOC "%s error: could not allocate memory. \n"
# define STR_ERR_MUTEX "%s error: could not create mutex. \n"

/********************************************** */
/*					Structs						*/
/********************************************** */

typedef struct s_philo	t_philo;

typedef struct s_table
{
	time_t				arrambam;
	unsigned int		nbr_thiru;
	pthread_t			dharma_raja;
	time_t				saagera_neram;
	time_t				saapida_neram;
	time_t				thunggara_neram;
	int					sapidum_ennikai;
	bool				sim_niruthavum;
	pthread_mutex_t		sim_stop_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		*fork_locks;
	t_philo				**thiru;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	pthread_mutex_t		meal_time_lock;
	time_t				khadaisi_unavu;
	t_table				*table;
}						t_philo;

typedef enum e_status
{
	MARANAM = 0,
	SAAPIDAVUM = 1,
	THONGGAVUM = 2,
	YOOSIKAVUM = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}						t_status;

/************************************************** */
/*					FUNCTIONS						*/
/************************************************** */

/*	parsing.c	*/
int			integer_atoi(char *str);
bool		is_valid_input(int ac, char **av);

/*	init.c	*/
t_table		*init_table(int ac, char **av, int i);

/*	time.c	*/
time_t		get_time_in_ms(void);
void		sim_start_delay(time_t start_time);
void		thiru_urrakam(t_table *table, time_t sleep_time);

/*	exit.c	*/
void		*free_table(t_table *table);
void		destroy_mutexes(t_table *table);
int			msg(char *str, char *detail, int exit_no);
int			error_failure(char *str, char *details, t_table *table);
void		*error_null(char *str, char *details, t_table *table);

/*	thiruvalluvar.c	*/
void		*thiruvalluvar(void *data);

/*	dharmaraja.c	*/
void		*dharma_raja(void *data);
bool		simulation_nindruvitatha(t_table *table);

/*	output.c	*/
void		write_outcome(t_table *table);
void		write_status(t_philo *philo, bool reaper_report, t_status status);

#endif