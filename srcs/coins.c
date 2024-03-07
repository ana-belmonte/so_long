/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:55:38 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 17:12:34 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	set_info_c(t_coin *coin, int i, int x, int y)
{
	coin[i].pos_x = x;
	coin[i].pos_y = y;
	coin[i].is_collected = 0;
}

t_coin	*create_coins(void)
{
	int		x;
	int		y;
	int		i;
	t_coin	*coin;

	coin = malloc(sizeof(t_coin) * engine()->map.c_count);
	if (!coin)
		return (NULL);
	y = 0;
	i = 0;
	while (engine()->map.map_grid[y])
	{
		x = 0;
		while (engine()->map.map_grid[y][x])
		{
			if (engine()->map.map_grid[y][x] == 'C')
			{
				set_info_c(coin, i, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
	return (coin);
}
