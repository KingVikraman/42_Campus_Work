/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:51:09 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/20 20:48:24 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
		return(STR_ERR_VALID);
	if (!is_valid_input)
		return (STR_EXIT_FAILURE);
}



/*Checklist of what handle for input.
:
	*Argument count must be 5 or 6.
	 ~av[1]-philo number, 1 - 200.
	 ~av[2]-check for time to die between 60 to INT_MAX.
	 ~av[3]-check for time to eat between 60 ot INT_MAX
	 ~av[4]-check for time to sleep between 60 ot INT_MAX
	 ~av[5]- check for count of eat 1 - INT_MAX
*/
