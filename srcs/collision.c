/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:00:14 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 19:01:51 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_wall_collision(int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_y >= engine()->map.h
		|| new_x >= engine()->map.w
		|| engine()->map.map_grid[new_y][new_x] == '1')
		return (1);
	else 
		return (0);
}

void	collect_coin(void)
{
	int	i;

	i = 0;
	while (i < engine()->map.total_c_count)
	{
		if (!engine()->map.coins[i].is_collected && 
			(int)engine()->map.player.pos_x == engine()->map.coins[i].pos_x 
			&& (int)engine()->map.player.pos_y == engine()->map.coins[i].pos_y)
		{
			engine()->map.c_count -= 1;
			engine()->map.coins[i].is_collected = 1;
		}
		i++;
	}
}

void	enemie_collision(void)
{
	int	i;
	int	p_posx;
	int	p_posy;

	i = 0;
	p_posx = (int)engine()->map.player.pos_x;
	p_posy = (int)engine()->map.player.pos_y;
	while (i < engine()->map.monster_c)
	{
		if (p_posx == engine()->map.enemies[i].pos_x && 
			p_posy == engine()->map.enemies[i].pos_y)
			exit(exit_free("YOU'RE DEAD sucker :/\n"));
		i++;
	}
}
