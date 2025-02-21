/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:42:54 by rvikrama          #+#    #+#             */
/*   Updated: 2024/10/09 19:08:16 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* this fucntion helps  check if the character is 
	negative or not.*/
int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

/* this fucntion helps to check if the 
	character is a digit or not*/
int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

/* this function is to check if there is
	there is any space characters.*/
int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

/* this function is to check if the given
	 argumets is valid or not. */
int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
