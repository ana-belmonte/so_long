/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:58:14 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/06 18:59:16 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	floodfill(char **map, int x, int y)
{
	if (x >= (engine()->map.w) || 
		y >= engine()->map.h || map[y][x] == '1'
		|| y <= 0 || x <= 0 || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

int	checker_path(char *filename)
{
	char	**newmap;

	newmap = create_map_cpy(filename);
	if (!newmap)
		return (1);
	floodfill(newmap, engine()->map.player.pos_x, engine()->map.player.pos_y);
	if (data_caract(newmap))
	{
		free_cpy(newmap);
		return (1);
	}
	free_cpy(newmap);
	return (0);
}

int	help_checker(char **map, int x, int y)
{
	if (map[y][x] == 'C')
		engine()->map.c_count++;
	if (map[y][x] == 'P')
	{
		engine()->map.p_count++;
		engine()->map.player.pos_x = x;
		engine()->map.player.pos_y = y;
	}
	if (map[y][x] == 'E')
		engine()->map.e_count++;
	if (map[y][x] == 'M')
		engine()->map.monster_c++;
	if (map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'P' 
		&& map[y][x] != 'E' && map[y][x] != '0' 
		&& map[y][x] != 'M' && map[y][x] != '\n')
		return (1);
	return (0);
}
