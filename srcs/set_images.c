/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 05:39:22 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/16 06:15:38 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void set_images()
{
	engine()->map.textures.player = mlx_xpm_file_to_image(engine()->mlx_connect, "images/p.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth);
	engine()->map.textures.wall = mlx_xpm_file_to_image(engine()->mlx_connect, "images/w.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth);
	engine()->map.textures.collect = mlx_xpm_file_to_image(engine()->mlx_connect, "images/c.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth)
	engine()->map.textures.exit = mlx_xpm_file_to_image(engine()->mlx_connect, "images/e.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth)
	engine()->map.textures.enemies = mlx_xpm_file_to_image(engine()->mlx_connect, "images/en.xpm", &engine()->map.textures.width, &engine()->map.textures.heigth)
}