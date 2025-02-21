/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:43:47 by rvikrama          #+#    #+#             */
/*   Updated: 2024/11/16 03:18:17 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}
	if (parse_map(argv[1], &game) == -1)
	{
		ft_printf("Error: Invalid map\n");
		return (1);
	}
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
