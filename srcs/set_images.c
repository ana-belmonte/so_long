/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 05:39:22 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/18 17:21:05 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void set_image()
{
	engine()->map.textures.player.img = mlx_xpm_file_to_image(engine()->mlx_connect, "images/player.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth);
 	engine()->map.textures.wall.img = mlx_xpm_file_to_image(engine()->mlx_connect, "images/floor.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth);
	engine()->map.textures.collect.img = mlx_xpm_file_to_image(engine()->mlx_connect, "images/collect.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth);
	engine()->map.textures.exit.img = mlx_xpm_file_to_image(engine()->mlx_connect, "images/exit.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth);
	engine()->map.textures.floor.img = mlx_xpm_file_to_image(engine()->mlx_connect, "images/floor2.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth);
}
