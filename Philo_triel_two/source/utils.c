/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:18:21 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/20 21:12:17 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int is_number(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


/* check for INT_MAX and minimum value, 
*	~one declare at  the header trhe stdlib and then use the INT_MAX 
*	constant  to insidacte the int max and set the minimum at 60.
*	~ before this step you should convert the string to integer with 
*	the fucntion called atoi. But unsually yiou can also one shot inistalize
*	to you table while shifting from intiger to atoi.
*	~*/