/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:00:14 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 15:05:24 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


int check_wall_collision(t_map_data map, int new_x, int new_y)
{
	if(new_x < 0 || new_y < 0 || new_y >= map.map_heigth || new_x >= map.map_width 
		|| map.map_grid[new_y][new_x] == '1')
		return(1);
	else 
		return(0);
}


void collect_coin()
{
	int i;

	i = 0;
	while(i < engine()->map.total_c_count)
	{
		if(!engine()->map.coins[i].is_collected && (int)engine()->map.player.pos_x == engine()->map.coins[i].pos_x 
			&& (int)engine()->map.player.pos_y == engine()->map.coins[i].pos_y)
		{
				engine()->map.c_count -= 1;
				engine()->map.coins[i].is_collected = 1;
		}
		i++;
	}
}

void enemie_collision()
{
	int i;

	i = 0;
	while(i < engine()->map.monster_c)
	{
		if((int)engine()->map.player.pos_x == engine()->map.enemies[i].pos_x 
			&& (int)engine()->map.player.pos_y == engine()->map.enemies[i].pos_y)
			exit(exit_free("YOU'RE DEAD sucker :/\n"));
		i++;
	}
}