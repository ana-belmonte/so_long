/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:00:30 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/14 11:22:57 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void init_variables(t_game *game)
{
	game->win_heigth = 0;
	game->win_width = 0;
	game->map. map_heigth = 0;
	game->map.map_width = 0;
	game->map.c_count = 0;
	game->map.map_grid = NULL;
	game->map.textures.player = NULL;
	game->map.textures.collect = NULL;
	game->map.textures.exit = NULL;
	game->map.textures.enemies = NULL;
	game->map.textures.wall = NULL;
}