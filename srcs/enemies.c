/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:30:12 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 14:49:36 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_enemie *create_enemies()
{
	int i;
	int x;
	int y;
	t_enemie *enemie;

	enemie = malloc(sizeof(t_enemie) * engine()->map.monster_c);
	if(!enemie)
		return(NULL);
	i = 0;
	y = 0;
	while(engine()->map.map_grid[y])
	{
		x = 0;
		while(engine()->map.map_grid[y][x])
		{
			if(engine()->map.map_grid[y][x] == 'M')
			{
				enemie[i].pos_x = x;
				enemie[i].pos_y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return(enemie);
}