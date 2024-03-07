/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:30:12 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 17:10:09 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	set_enemies_p(t_enemie *enemie, int i, int x, int y)
{
	enemie[i].pos_x = x;
	enemie[i].pos_y = y;
}

t_enemie	*create_enemies(void)
{
	int			i;
	int			x;
	int			y;
	t_enemie	*enemie;

	enemie = malloc(sizeof(t_enemie) * engine()->map.monster_c);
	if (!enemie)
		return (NULL);
	i = 0;
	y = 0;
	while (engine()->map.map_grid[y])
	{
		x = 0;
		while (engine()->map.map_grid[y][x])
		{
			if (engine()->map.map_grid[y][x] == 'M')
			{
				set_enemies_p(enemie, i, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
	return (enemie);
}
