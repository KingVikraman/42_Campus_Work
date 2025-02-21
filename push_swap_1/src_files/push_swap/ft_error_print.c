/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:52 by rvikrama          #+#    #+#             */
/*   Updated: 2024/10/09 19:10:25 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* here there will be a function that will print 
	out an error message if there are any errors.
*/
void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

/* its said by balckbox that instaed of exit(1);
you can also put exit(EXIT_FAILURE);
maybe you can try thayt later toi see if it works */