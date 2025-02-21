/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:16:29 by rvikrama          #+#    #+#             */
/*   Updated: 2024/10/09 19:11:46 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/* while the arguments are valid, we can start to add 
	them while we can into the stack, one by one with
	the loop. Meanwhile atoi will take the number and 
	turn it into an integer value where we can make math 
	operations with it.Now with stack_new we can create 
	a new mode for the current argumnets without linking 
	it to list. We make linking stage in ft_add_back call.
*/
void	list_arguments(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_add_back(stack_a, ft_stack_new(ft_atoi(argv[i])));
		i++;
	}
}
