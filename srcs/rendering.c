/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:27 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 15:48:15 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_image	*assets(int x, int y)
{
	if (engine()->map.map_grid[x][y] == 'E' )
		return (&engine()->map.t_textures.floor);
	if (engine()->map.map_grid[x][y] == 'C' )
		return (&engine()->map.t_textures.floor);
	if (engine()->map.map_grid[x][y] == 'M' )
		return (&engine()->map.t_textures.floor);
	if (engine()->map.map_grid[x][y] == '1' )
		return (&engine()->map.t_textures.wall);
	if (engine()->map.map_grid[x][y] == '0' )
		return (&engine()->map.t_textures.floor);
	return (NULL);
}

void	render_map(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < engine()->map.h)
	{
		x = 0;
		while (x < engine()->map.w)
		{
			if (assets(y, x))
				cpy_to_win_image(&engine()->w_img, 
					assets(y, x), x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(engine()->mlx_cnt,
		engine()->mlx_win, engine()->w_img.img, 0, 0);
}

void	set_new_pos(void)
{
	float	add_y;
	float	add_x;

	add_y = engine()->delta_time * engine()->velocidade
		* engine()->map.player.dir_y;
	add_x = engine()->delta_time * engine()->velocidade
		* engine()->map.player.dir_x;
	engine()->map.player.pos_y -= add_y;
	engine()->map.player.pos_x -= add_x;
}

void	render_player(void)
{
	float		x;
	float		y;
	static int	count;
	static int	curr_frame;

	if (engine()->map.wall == 1)
		set_new_pos();
	x = engine()->map.player.pos_x;
	y = engine()->map.player.pos_y;
	if (engine()->map.player.dir_x == 0 && engine()->map.player.dir_y == 0)
		cpy_to_win_image(&engine()->w_img, 
			&engine()->map.player.curr_frame, x * 64, y * 64);
	else
	{
		if (!(count % 10))
			curr_frame++;
		cpy_to_win_image(&engine()->w_img, 
			&engine()->map.player.cur_sprite[curr_frame % 2], x * 64, y * 64);
		count++;
	}
	engine()->map.wall = 0;
	mlx_put_image_to_window(engine()->mlx_cnt, engine()->mlx_win,
		engine()->w_img.img, 0, 0);
}

void	render_exit(void)
{
	int	x;
	int	y;

	y = 0;
	while (engine()->map.map_grid[y])
	{
		x = 0;
		while (engine()->map.map_grid[y][x])
		{
			if (engine()->map.map_grid[y][x] == 'E')
			{
				engine()->map.e_pos_x = x;
				engine()->map.e_pos_y = y;
				cpy_to_win_image(&engine()->w_img, 
					&engine()->map.t_textures.exit, x * 64, y * 64);
				break ;
			}
			x++;
		}
		y++;
	}
}
