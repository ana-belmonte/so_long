/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:00:30 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/06 22:01:49 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_variables(t_game *game)
{
	game->moves = NULL;
	game->itoa = NULL;
	game->map.map_grid = NULL;
	game->map.coins = NULL;
	game->velocidade = 3.5;
	game->map.player.curr_frame = game->map.player.standing[0];
	init_image(&game->map.t_textures.wall);
	init_image(&game->map.t_textures.floor);
	init_image(&game->map.t_textures.exit);
	init_image(&game->w_img);
}

void	init_image(t_image *image)
{
	image->img = NULL;
	image->address = NULL;
	image->bpp = 0;
	image->endian = 0;
	image->line_length = 0;
	image->width = 0;
	image->height = 0;
}
