/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:15:12 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/18 17:09:25 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void free_cpy(char **newmap)
{
	int i;

	i = 0;
	while(newmap[i])
	{
		free(newmap[i]);
		i++;
	}
	free(newmap);
}

void	clean_map_grid(char **map_grid) 
{
	int i;

	i = 0;
	while(i < engine()->map.map_heigth)
	{
		free(map_grid[i]);
		i++;
	}
	free(map_grid);
}

void clean_image(t_image *img)
{
	free(img.address);
	free(img.bpp);
	free(img.endian);
	free(img.line_length);
	mlx_destroy_image(engine()->mlx_connect, img.img);
	free(img);
}

void clean_textures(t_texture *textures)
{
	clean_image(textures->player);
	clean_image(textures->collect);
	clean_image(textures->exit);
	clean_image(textures->floor);
	clean_image(textures->wall);
}

int exit_free(char *error)
{
	t_game *game;

	if(error)
		ft_putstr_fd(error, 2);
	game = engine();
	if(game->map.map_grid)
	{
		clean_map_grid(game->map.map_grid);
		if(game->map.textures.player != NULL)
			clean_textures(&game->map.textures);
	}
	if(game->mlx_connect)
	{
		mlx_clear_window(game->mlx_connect, game->mlx_win);
		mlx_destroy_window(game->mlx_connect, game->mlx_win);
		mlx_destroy_display(game->mlx_connect);
		free(engine()->mlx_connect);
	}
	return(1);
}