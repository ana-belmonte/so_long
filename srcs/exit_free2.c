/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:28:47 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 17:42:48 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_cpy(char **newmap)
{
	int	i;

	i = 0;
	while (newmap[i])
	{
		free(newmap[i]);
		i++;
	}
	free(newmap);
}

void	clean_map_grid(char **map_grid)
{
	int	i;

	i = 0;
	while (i < engine()->map.h)
	{
		free(map_grid[i]);
		i++;
	}
	free(map_grid);
}

void	clean_image(t_image img)
{
	mlx_destroy_image(engine()->mlx_cnt, img.img);
}

void	clean_t_textures(t_textures t_textures)
{
	clean_image(t_textures.exit);
	clean_image(t_textures.floor);
	clean_image(t_textures.wall);
}
