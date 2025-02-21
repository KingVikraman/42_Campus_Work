/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:12:15 by rvikrama          #+#    #+#             */
/*   Updated: 2025/02/16 18:08:24 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	contains_only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
/* contains_only_digits:
 *	Checks if a string contains only digits 0 - 9.
 *	Returns true if the string only contains digits.
 *	Returns false if the string contains a character that is not a digit.
 */

int	integer_atoi(char *str)
{
	unsigned long long int	nb;
	int						i;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}
/*integer_atoi:
 *	converts a digit-only string into a positive integral,
 *		Returns the converted number btw 0 and  INT_MAX
 *	Returns -1 if the converted number exceeds INT_MAX.
 */

bool	is_valid_input(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!contains_only_digits(av[i]))
			return (msg(STR_ERR_INPUT_DIGIT, av[i], false));
		nb = integer_atoi(av[i]);
		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (msg(STR_ERR_INPUT_POFLOW, STR_MAX_PHILOS, false));
		if (i != 1 && nb == -1)
			return (msg(STR_ERR_INPUT_DIGIT, av[i], false));
		i++;
	}
	return (true);
}

/* is_valid_input:
 *	checks if all required arguments are valid i.e. is a string of
 *	digits only, which does not exceed INT_MAX, Also checks if the
 *	number of philosophers is valid (between 1, and MAX_PHILOS).
 *	Returns true if all arguments are valid, false if one of them
 * 	is invalid.*/