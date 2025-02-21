/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:16:09 by rvikrama          #+#    #+#             */
/*   Updated: 2024/10/09 19:15:37 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* So practically this fuction deos three things:

	1)Firstly it checks if the number of the input is less than 2.
	2)secondly it check if the number of the input is equal to 2.
	  if it is then it means it is quoted string.
	3)Thirdly it check if the number of input is greater than 2,
	  if it is, then it lists the arguments.
*/
t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		ft_error();
	else if (argc == 2)
		stack_a = ft_parse_args_quoted(argv);
	else
	{
		list_arguments(argv, &stack_a);
	}
	return (stack_a);
}
