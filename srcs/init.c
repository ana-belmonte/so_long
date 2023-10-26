/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:00:30 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/26 17:18:51 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void init_variables(t_game *game)
{
	game->map.map_heigth = 0;
	game->map.map_width = 0;
	game->map.c_count = 0;
	game->n_moves = 0;
	game->map.player.pos_x = 0;
	game->map.player.pos_y = 0;
	game->map.map_grid = NULL;
	game->velocidade = 2.0;
	//init_image(&game->map.textures.player);
	init_image(&game->map.textures.wall);
	//init_image(&game->map.textures.floor);
	//init_image(&game->map.textures.collect);
	//init_image(&game->map.textures.enemies);
	init_image(&game->map.textures.exit);
	init_image(&game->win_image);
	//game->map.textures.enemies = NULL;
	//game->map.textures.wall = NULL;
}

void init_image(t_image *image)
{
	image->img = NULL;
	image->address = NULL;
	image->bpp = 0;
	image->endian = 0;
	image->line_length = 0;
	image->width = 0;
	image->height = 0;
}