/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:46:28 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/18 17:12:15 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void move_left()
{
	float x;
	float y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x][y - 0.5] != '1')
	{
		if(engine()->map.map_grid[x][y - 0.5] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x][y - 0.5] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x][y - 1] = 'P';
		engine()->map.p_pos_y--;
		engine()->n_moves++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(engine()->n_moves, 1);
		ft_putchar_fd('\n', 1);
	}	
}

void move_right()
{
	float x;
	float y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x][y + 0.5] != '1')
	{
		if(engine()->map.map_grid[x][y + 0.5] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x][y + 0.5] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x][y + 0.5] = 'P';
		engine()->map.p_pos_y++;
		engine()->n_moves++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(engine()->n_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void move_up()
{
	float x;
	float y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x - 0.5][y] != '1')
	{
		if(engine()->map.map_grid[x - 1][y] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x - 0.5][y] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x - 0.5][y] = 'P';
		engine()->map.p_pos_x--;
		engine()->n_moves++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(engine()->n_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void move_down()
{
	float x;
	float y;

	x = engine()->map.p_pos_x;
	y = engine()->map.p_pos_y;
	if(engine()->map.map_grid[x + 0.5][y] != '1')
	{
		if(engine()->map.map_grid[x + 0.5][y] == 'C' && engine()->map.c_count > 0)
			engine()->map.c_count--;
		if(engine()->map.c_count == 0 && engine()->map.map_grid[x + 0.5][y] == 'E')
			exit(exit_free("SORRY B-A-B-Y"));
		engine()->map.map_grid[x][y] = '0';
		engine()->map.map_grid[x + 1][y] = 'P';
		engine()->map.p_pos_x++;
		engine()->n_moves++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(engine()->n_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}
