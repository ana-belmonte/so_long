/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:08:51 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 15:30:54 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	set_pos_e(int i, t_enemie *enemies)
{
	engine()->map.player.dir = (rand() % 4);
	if (engine()->map.player.dir == 0 && 
		!check_wall_collision(enemies[i].pos_x, enemies[i].pos_y - 1))
		enemies[i].pos_y -= 1;
	if (engine()->map.player.dir == 1 && 
		!check_wall_collision(enemies[i].pos_x, enemies[i].pos_y + 1))
		enemies[i].pos_y += 1;
	if (engine()->map.player.dir == 2 && 
		!check_wall_collision(enemies[i].pos_x - 1, enemies[i].pos_y))
		enemies[i].pos_x -= 1;
	if (engine()->map.player.dir == 3 && 
		!check_wall_collision(enemies[i].pos_x + 1, enemies[i].pos_y))
		enemies[i].pos_x += 1;
}

void	update_enemie_pos(void)
{
	int						i;
	double					time_interval;
	static struct timeval	last_time;
	double					time_passed;
	struct timeval			current_time;

	if (last_time.tv_sec == 0)
		gettimeofday(&last_time, NULL);
	gettimeofday(&current_time, NULL);
	time_interval = 0.5;
	time_passed = (current_time.tv_sec - last_time.tv_sec) 
		+ (current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	i = 0;
	if (time_passed >= time_interval)
	{
		while (i < engine()->map.monster_c)
		{
			set_pos_e(i, engine()->map.enemies);
			i++;
		}
		last_time = current_time;
	}
}

void	update_player_pos(void)
{
	float	new_x;
	float	new_y;
	float	dir_veloc_x;
	float	dir_veloc_y;

	dir_veloc_x = engine()->map.player.dir_x * engine()->velocidade;
	dir_veloc_y = engine()->map.player.dir_y * engine()->velocidade;
	new_x = engine()->map.player.pos_x + (engine()->delta_time * dir_veloc_x);
	new_y = engine()->map.player.pos_y + (engine()->delta_time * dir_veloc_y);
	if (!check_wall_collision(new_x, new_y) 
		&& !check_wall_collision(new_x + 0.40, new_y + 0.50) 
		&& !check_wall_collision(new_x, new_y + 0.50) 
		&& !check_wall_collision(new_x + 0.40, new_y))
	{
		if ((int)new_y != (int)engine()->map.player.pos_y 
			|| (int)new_x != (int)engine()->map.player.pos_x)
			engine()->n_moves += 1;
		engine()->map.player.pos_x = new_x;
		engine()->map.player.pos_y = new_y;
	}
}

void	update_delta_time(void)
{
	static struct timeval	last_time;
	struct timeval			current_time;

	gettimeofday(&current_time, NULL);
	(engine()->delta_time) = (current_time.tv_sec - last_time.tv_sec)
		+(current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	last_time = current_time;
}

int	update(void)
{
	update_delta_time();
	update_player_pos();
	update_enemie_pos();
	enemie_collision();
	render_map();
	render_exit();
	render_player();
	render_enemies();
	render_coin();
	collect_coin();
	endgame();
	(engine()->itoa) = ft_itoa(engine()->n_moves);
	(engine()->moves) = ft_strjoin("MOVES:", engine()->itoa);
	free(engine()->itoa);
	mlx_string_put(engine()->mlx_cnt, engine()->mlx_win, 
		(engine()->map.w - 0.9) * 64, 
		(engine()->map.h + 0.5 - engine()->map.h) * 64, 
		(int)0x00ffffff, engine()->moves);
	free(engine()->moves);
	return (0);
}
