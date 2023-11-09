/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:15:12 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 14:46:42 by aaires-b         ###   ########.fr       */
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

void clean_image(t_image img)
{
	//free(img.address);
	mlx_destroy_image(engine()->mlx_connect, img.img);
}

void clean_textures(textures *textures)
{
	clean_image(textures->exit);
	clean_image(textures->floor);
	clean_image(textures->wall);
}

void free_coins(t_coin *coins)
{
	int i;

	i = 0;
	while(i < engine()->map.c_count)
	{
		free_loop_player(coins[i].sprite, 4);
		i++;
	}
}

void free_enemies(t_enemie *enemies)
{
	int i;

	i = 0;
	while(i < engine()->map.monster_c)
	{
		free_loop_player(enemies[i].sprite, 10);
		i++;
	}
}
void free_loop_player(t_image *image, int len)
{
	int i;
	i = 0;
	while(i < len)
	{
		clean_image(image[i]);
		i++;
	}
}
void free_assets(t_map_data map)
{
	if(map.player.standing[0].img)
		free_loop_player(map.player.standing, 4);
	if(map.player.left[0].img)
		free_loop_player(map.player.left, 2);
	if(map.player.front[0].img)
		free_loop_player(map.player.front, 2);
	if(map.player.rigth[0].img)
		free_loop_player(map.player.rigth, 2);
	if(map.player.back[0].img)
		free_loop_player(map.player.back, 2);
	if(map.coins[0].sprite[0].img)
		free_coins(map.coins);
		//free_loop_player(map.coins.sprite, 4);
	if(map.enemies[0].sprite[0].img)
		free_enemies(map.enemies);
}
int exit_free(char *error)
{
	t_game *game;

	if(error)
		ft_putstr_fd(error, 2);
	game = engine();
	if(game->map.map_grid)
		clean_map_grid(game->map.map_grid);
	if(game->mlx_connect)
	{
		free_assets(game->map);
		clean_image(game->win_image);
		mlx_clear_window(game->mlx_connect, game->mlx_win);
		mlx_destroy_window(game->mlx_connect, game->mlx_win);
		mlx_destroy_display(game->mlx_connect);
		free(engine()->mlx_connect);
	}
	return(1);
}
