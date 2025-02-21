/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:21:30 by rvikrama          #+#    #+#             */
/*   Updated: 2024/10/09 21:25:21 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* int argc, represents the number of command-line 
	arguments passed to the program.
	So, technically what happens is that, first we 
	declare a variable called a as a pointer to a t_stack.
	After that what happens is that the ft_process porcesses 
	the argc and argv and returns the value assigned to a.
	Then there is a if loop where it checks weather if 
	there are no argumnets or if there are duplicate numbers
	in the stack, if there are then the program will free 
	the whole thing and proceed to ft_error.
	Now if the ft_free returns a non_zero value, the 
	program calls ft_sort to sort the stack.
	once the staack is sorted, the programm finally frees 
	the memory allocated for a usiing ft_free and returns
	an exit status of 0 to show a succsesful run.
*/
int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
