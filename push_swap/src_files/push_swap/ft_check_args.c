/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:23:59 by rvikrama          #+#    #+#             */
/*   Updated: 2024/10/09 18:09:19 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* so this fuction isalpha, what it does, is that it checks
   weather the character is alphanumerical or not.
*/
int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 33 && c <= 42) || (c == 44)
		|| (c == 46) || (c == 47) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

/* well here the argumnets are sent to make a ASCII check.
   reguarding theh alphanumeric values.
*/
void	alpha_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

/* And finally with this function it is checked 
	weather the arguments include alphanumeric or not.
*/	
bool	check_args(char **argv)
{
	alpha_check(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}
