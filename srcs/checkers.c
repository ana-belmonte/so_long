/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:40:33 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 14:34:50 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void floodfill(char **map, int x, int y)
{
	if(x >= (engine()->map.map_width)|| y >= engine()->map.map_heigth || map[y][x] == '1'
		|| y <= 0 || x <= 0 || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

int checker_path(char *filename)
{
	char **newmap;

	newmap = create_map_cpy(filename);
	if(!newmap)
		return(1);
	floodfill(newmap, engine()->map.player.pos_x, engine()->map.player.pos_y);
	if (data_caract(newmap))
	{
		free_cpy(newmap);
		return(1);
	}
	free_cpy(newmap);
	return (0);
}

int checker_arg(char *arg)
{
	int flag;
	int i;

	i = 0;
	flag = 0;
	if(!arg)
		return(1);
	while(arg[i])
	{
		if(arg[i + 1] == '.')
		{
			flag = 1;
			if(arg[i + 2] != 'b' || arg[i + 3] != 'e' || arg[i + 4] != 'r')
				return(1);
		}
		i++;
	}
	if(!flag)
		return(1);
	return(0);
}

int checker_charact(char **map)
{
	int x;
	int  y;
	int p_count;
	int e_count;

	e_count = 0;
	p_count = 0;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'C')
				engine()->map.c_count++;
			if(map[y][x] == 'P')
			{
				p_count++;
				engine()->map.player.pos_x = x;
				engine()->map.player.pos_y = y;
			}
			if(map[y][x] == 'E')
				e_count++;
			if(map[y][x] == 'M')
				engine()->map.monster_c++;
			if (map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'P' 
				&& map[y][x] != 'E' && map[y][x] != '0'  && map[y][x] != 'M' && map[y][x] != '\n')
					return (1);
			x++;
		}
		y++;
	}
	engine()->map.total_c_count = engine()->map.c_count;
	if(engine()->map.c_count < 1 || (e_count + p_count) != 2)
		return (1);
	return (0);
}
int checker_map_size(char **map)
{
	int x;
	int y;

	x = 0;
	while(map[0][x] != '\n')
		x++;
	engine()->map.map_width = x;
	y = 1;
	while(map[y])
	{
		x = 0;
		while(map[y][x]  && map[y][x] != '\n')
			x++;
		if((x) != engine()->map.map_width)
			return(1);
		y++;
	}
	return(0);
}


int checker_walls(char **map)
{
	int x;
	int y;
	int width;
	int heigth;

	y = 0;
	width = engine()->map.map_width;
	heigth = engine()->map.map_heigth;
	while(map[y])
	{
		x = 0;
		while(map[y][x] && map[y][x] != '\n')
		{
			if(map[0][x] != '1' || map[y][0] != '1' || map[heigth - 1][x] != '1'
				|| map[y][width - 1] != '1')
				return(1);
			x++;
		}
		y++;
	}
	return(0);
}

int checker_map(char *filename)
{	
	if(checker_map_size(engine()->map.map_grid))
		return(1);
	if(checker_walls(engine()->map.map_grid))
		return(1);
	if (checker_charact(engine()->map.map_grid))
		return(1);
	if(checker_path(filename))
		return (1);
	return(0);
}