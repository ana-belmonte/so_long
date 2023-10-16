/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:40:33 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/16 12:38:10 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void floodfill(char **map, int x, int y)
{
	if(x >= (engine()->map.map_heigth)|| y >= engine()->map.map_width || map[x][y] == '1'
		|| y <= 0 || x <= 0 || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

int checker_path(char *filename)
{
	char **newmap;
	int i;

	i = 0;
	newmap = create_map_cpy(filename);
	if(!newmap)
		return(1);
	floodfill(newmap, engine()->map.p_pos_x, engine()->map.p_pos_y);
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
	int y;
	int p_count;
	int e_count;

	e_count = 0;
	p_count = 0;
	x = 0;
	while(map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if(map[x][y] == 'C')
				engine()->map.c_count++;
			if(map[x][y] == 'P')
			{
				p_count++;
				engine()->map.p_pos_x = x;
				engine()->map.p_pos_y = y;
			}
			if(map[x][y] == 'E')
				e_count++;
			if (map[x][y] != '1' && map[x][y] != 'C' && map[x][y] != 'P' 
				&& map[x][y] != 'E' && map[x][y] != '0' && map[x][y] != '\n')
					return (1);
			y++;
		}
		x++;
	}
	if(engine()->map.c_count < 1 || (e_count + p_count) != 2)
		return (1);
	return (0);
}
int checker_map_size(char **map)
{
	int x;
	int y;

	y = 0;
	while(map[0][y] != '\n')
		y++;
	engine()->map.map_width = y - 1;
	x = 1;
	while(map[x])
	{
		y = 0;
		while(map[x][y]  && map[x][y] != '\n')
			y++;
		if((y - 1)!= engine()->map.map_width)
			return(1);
		x++;
	}
	return(0);
}


int checker_walls(char **map)
{
	int x;
	int y;
	int width;
	int heigth;

	x = 0;
	width = engine()->map.map_width;
	heigth = engine()->map.map_heigth;
	while(map[x])
	{
		y = 0;
		while(map[x][y] && map[x][y] != '\n')
		{
			if(map[0][y] != '1' || map[x][0] != '1' || map[heigth - 1][y] != '1'
				|| map[x][width] != '1')
				return(1);
			y++;
		}
		x++;
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