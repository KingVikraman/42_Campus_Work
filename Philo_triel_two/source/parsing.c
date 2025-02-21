/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:04:09 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/20 16:51:55 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo"

int check_if_number(char **av)
{
	int i;
	
	i = 0;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (1)
	i++;
	}
	return (0);
}

int check if numbers

int     is_valid_input