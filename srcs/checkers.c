/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:40:33 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/10 13:42:06 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	checker_arg(char *arg)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	if (!arg)
		return (1);
	while (arg[i])
	{
		if (arg[i + 1] == '.')
		{
			flag = 1;
			if (arg[i + 2] != 'b' || arg[i + 3] != 'e' || arg[i + 4] != 'r' 
				|| arg[i + 5] != '\0') // fazer strcmp
				return (1);
		}
		i++;
	}
	if (!flag)
		return (1);
	return (0);
}

int	checker_charact(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (help_checker(map, x, y) == 1)
				return (1);
			x++;
		}
		y++;
	}
	engine()->map.total_c_count = engine()->map.c_count;
	if (engine()->map.c_count < 1 || 
		(engine()->map.e_count + engine()->map.p_count) != 2)
		return (1);
	return (0);
}

int	checker_map_size(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[0][x] != '\n')
		x++;
	engine()->map.w = x;
	y = 1;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
			x++;
		if ((x) != engine()->map.w)
			return (1);
		y++;
	}
	return (0);
}

int	checker_walls(char **map)
{
	int	x;
	int	y;
	int	width;
	int	heigth;

	y = 0;
	width = engine()->map.w;
	heigth = engine()->map.h;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[0][x] != '1' || map[y][0] != '1' 
				|| map[heigth - 1][x] != '1'
				|| map[y][width - 1] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	checker_map(char *filename)
{
	if (checker_map_size(engine()->map.map_grid))
		return (1);
	if (checker_walls(engine()->map.map_grid))
		return (1);
	if (checker_charact(engine()->map.map_grid))
		return (1);
	if (checker_path(filename))
		return (1);
	return (0);
}
