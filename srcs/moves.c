/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:46:28 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/16 13:34:36 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void move_left()
{
	int x;
	int y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x][y - 1] != '1')
	{
		if(engine()->map.map_grid[x][y - 1] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
			//show image exit
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x][y - 1] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x][y - 1] = 'P';
		engine()->map.p_pos_y--;
	}	
}

void move_right()
{
	int x;
	int y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x][y + 1] != '1')
	{
		if(engine()->map.map_grid[x][y + 1] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
			//show image exit
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x][y + 1] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x][y + 1] = 'P';
		engine()->map.p_pos_y++;
	}
}

void move_up()
{
	int x;
	int y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x - 1][y] != '1')
	{
		if(engine()->map.map_grid[x - 1][y] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
			//show image exit
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x - 1][y] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x - 1][y] = 'P';
		engine()->map.p_pos_x--;
	}
}

void move_down()
{
	int x;
	int y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x + 1][y] != '1')
	{
		if(engine()->map.map_grid[x + 1][y] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x + 1][y] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x + 1][y] = 'P';
		engine()->map.p_pos_x++;
	}
}
