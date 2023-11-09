/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:27 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 14:43:30 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


t_image *assets(int x, int y)
{
	//if(engine()->map.map_grid[x][y] == 'P')
		//return(engine()->map.textures.player)
	if(engine()->map.map_grid[x][y] == 'E' )
		return(&engine()->map.textures.floor);
	if(engine()->map.map_grid[x][y] == 'C' )
		return(&engine()->map.textures.floor);
	if(engine()->map.map_grid[x][y] == 'M' )
		return(&engine()->map.textures.floor);
	if(engine()->map.map_grid[x][y] == '1' )
		return(&engine()->map.textures.wall);
	if(engine()->map.map_grid[x][y] == '0' )
		return(&engine()->map.textures.floor);
	return (NULL);
}

void render_map()
{	
	int x;
	int y;	 

	y = 0;
	while(y < engine()->map.map_heigth)
	{
		x = 0;
		while(x < engine()->map.map_width)
		{
			if(assets(y, x))
				cpy_to_win_image(&engine()->win_image, assets(y, x), x * 64 , y * 64);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(engine()->mlx_connect, engine()->mlx_win, engine()->win_image.img, 0, 0);
}

void render_player()
{
	float x;
	float y;
	static int count;
	static int curr_frame;
	
	//printf("%f \n", engine()->map.player.pos_x);
	if(engine()->map.wall == 1)
	{
		engine()->map.player.pos_y -= engine()->delta_time * engine()->velocidade * engine()->map.player.dir_y;
		engine()->map.player.pos_x -= engine()->delta_time * engine()->velocidade * engine()->map.player.dir_x;
	}
	x = engine()->map.player.pos_x;
	y = engine()->map.player.pos_y;
	if(engine()->map.player.dir_x == 0 && engine()->map.player.dir_y == 0)
		cpy_to_win_image(&engine()->win_image, &engine()->map.player.curr_frame, x * 64 , y * 64);
	else
	{
		if(!(count % 10))
			curr_frame++;
		cpy_to_win_image(&engine()->win_image, &engine()->map.player.cur_sprite[curr_frame % 2], x * 64 , y * 64);
		count++;
	}
	engine()->map.wall = 0;
	mlx_put_image_to_window(engine()->mlx_connect, engine()->mlx_win, engine()->win_image.img, 0, 0);
}

void render_exit()
{
	int x;
	int y;
	
	y = 0;
	while(engine()->map.map_grid[y])
	{
		x = 0;
		while(engine()->map.map_grid[y][x])
		{
			if(engine()->map.map_grid[y][x] == 'E')
			{
				engine()->map.e_pos_x = x;
				engine()->map.e_pos_y = y;
				cpy_to_win_image(&engine()->win_image, &engine()->map.textures.exit, x * 64, y * 64);
				break ;
			}
			x++;
		}
		y++;
	}
}

void render_enemies()
{
	static int curr_frame;
	static int count;
	int i;
	int x;
	int y;
	
	i = 0;
	while(i < engine()->map.monster_c)
	{
		if(!(count % 40))
			curr_frame++;
		x = engine()->map.enemies[i].pos_x;
		y = engine()->map.enemies[i].pos_y;
		cpy_to_win_image(&engine()->win_image, &engine()->map.enemies[i].sprite[curr_frame % 10], x * 64 , y * 64);
		count++;
		i++;
	}
}

void render_coin()
{
	int x;
	int y;
	static int curr_frame;
	static int count;
	int i;

	i = 0;
	while(i < engine()->map.total_c_count)
	{
		if(!engine()->map.coins[i].is_collected)
		{
			if (!(count % 40))
				curr_frame++;
			x = engine()->map.coins[i].pos_x;
			y = engine()->map.coins[i].pos_y;
			cpy_to_win_image(&engine()->win_image, &engine()->map.coins[i].sprite[curr_frame % 4], x * 64 , y * 64);
			count++;
		}
		i++;
	}
}
