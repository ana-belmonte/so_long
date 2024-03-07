/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:15:12 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 20:00:53 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_coins(t_coin *coins)
{
	int	i;

	i = 0;
	while (i < engine()->map.total_c_count)
	{
		free_loop_player(coins[i].sprite, 4);
		i++;
	}
	free(coins);
}

void	free_enemies(t_enemie *enemies)
{
	int	i;

	i = 0;
	while (i < engine()->map.monster_c)
	{
		free_loop_player(enemies[i].sprite, 10);
		i++;
	}
	free(enemies);
}

void	free_loop_player(t_image *image, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		clean_image(image[i]);
		i++;
	}
}

void	free_assets(t_map_data map)
{
	if (map.player.standing[0].img)
		free_loop_player(map.player.standing, 4);
	if (map.player.left[0].img)
		free_loop_player(map.player.left, 2);
	if (map.player.front[0].img)
		free_loop_player(map.player.front, 2);
	if (map.player.rigth[0].img)
		free_loop_player(map.player.rigth, 2);
	if (map.player.back[0].img)
		free_loop_player(map.player.back, 2);
	if (engine()->map.c_count >= 0)
	{
		if (map.coins[0].sprite[0].img)
			free_coins(map.coins);
	}
	if (engine()->map.monster_c > 0)
	{
		if (map.enemies[0].sprite[0].img)
			free_enemies(map.enemies);
	}
}

int	exit_free(char *error)
{
	t_game	*game;

	if (error)
		ft_putstr_fd(error, 2);
	game = engine();
	if (game->map.map_grid)
		clean_map_grid(game->map.map_grid);
	if (game->mlx_cnt)
	{
		free_assets(game->map);
		clean_t_textures(game->map.t_textures);
		clean_image(game->w_img);
		mlx_clear_window(game->mlx_cnt, game->mlx_win);
		mlx_destroy_window(game->mlx_cnt, game->mlx_win);
		mlx_destroy_display(game->mlx_cnt);
		free(engine()->mlx_cnt);
	}
	return (1);
}
