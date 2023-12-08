/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:27:45 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 18:31:25 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_game *engine()
{
	static t_game game;
	
	return (&game);
}

void update_enemie_pos()
{
	int dir;
	int i;
	double time_interval;
	static struct timeval last_time;
	double time_passed;
	struct timeval current_time;

	if(last_time.tv_sec == 0)
		gettimeofday(&last_time, NULL);
	gettimeofday(&current_time, NULL);
	time_interval = 0.5;
	time_passed = (current_time.tv_sec - last_time.tv_sec) + (current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	printf("last sec: %ld\n",last_time.tv_sec);
	printf("curr usec: %ld \n",current_time.tv_usec);
	printf("curr sec :%ld\n",current_time.tv_sec);
	printf("last usec :%ld \n",last_time.tv_usec);
	i = 0;
	printf("time passed :%f\n", time_passed);
	if(time_passed >= time_interval)
	{
		while(i < engine()->map.monster_c)
		{
			dir = (rand() % 4);
			if(dir == 0 && !check_wall_collision(engine()->map, engine()->map.enemies[i].pos_x, engine()->map.enemies[i].pos_y - 1))
				engine()->map.enemies[i].pos_y -= 1;
			if(dir == 1 && !check_wall_collision(engine()->map, engine()->map.enemies[i].pos_x, engine()->map.enemies[i].pos_y + 1))
				engine()->map.enemies[i].pos_y += 1;
			if(dir == 2 && !check_wall_collision(engine()->map, engine()->map.enemies[i].pos_x - 1, engine()->map.enemies[i].pos_y))
				engine()->map.enemies[i].pos_x -= 1;
			if(dir == 3 && !check_wall_collision(engine()->map, engine()->map.enemies[i].pos_x + 1, engine()->map.enemies[i].pos_y))
				engine()->map.enemies[i].pos_x += 1;
			i++;
		}
		last_time = current_time;
	}
	
}

void update_player_pos()
{
	float new_x;
	float new_y;
	
	new_x = engine()->map.player.pos_x + (engine()->delta_time * engine()->map.player.dir_x * engine()->velocidade);
	new_y = engine()->map.player.pos_y + (engine()->delta_time * engine()->map.player.dir_y * engine()->velocidade);
	if(!check_wall_collision(engine()->map, new_x, new_y) && !check_wall_collision(engine()->map, new_x + 0.40, new_y + 0.50) &&
		!check_wall_collision(engine()->map, new_x, new_y + 0.50) && !check_wall_collision(engine()->map, new_x + 0.40, new_y))
	{
		engine()->map.player.pos_x = new_x;
		engine()->map.player.pos_y = new_y;
	}
}	

void update_delta_time() // deltatime = time that passed between two events, in animation keeps everything flow well by controling the time and velocity between them 
{
	static struct timeval last_time; // keeps value of last call until program ends!!!!
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	engine()->delta_time = (current_time.tv_sec - last_time.tv_sec) +
						(current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	last_time = current_time; // reset the time
}

int update()
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
	return(0);
}

void init_window()
{
	engine()->mlx_connect = mlx_init();
	if(!engine()->mlx_connect)
		exit(exit_free("fail connecting to interface\n"));
	engine()->mlx_win = mlx_new_window(engine()->mlx_connect, engine()->map.map_width * 64, engine()->map.map_heigth * 64, "cacosidade");
	if(!engine()->mlx_win)
		exit(exit_free("fail initing window\n"));
}
void create_new_img()
{
	engine()->win_image.img = mlx_new_image(engine()->mlx_connect, engine()->map.map_width * 64, engine()->map.map_heigth * 64);
	if(!engine()->win_image.img)
		exit(exit_free("fail initing image\n"));
	engine()->win_image.address = mlx_get_data_addr(engine()->win_image.img, &engine()->win_image.bpp, &engine()->win_image.line_length, &engine()->win_image.endian);
}

int main(int ac, char **av)
{
	if(ac != 2)
		return (exit_free("invalid number of args\n"));
	if(checker_arg(av[1]))
		return(exit_free("invalid args\n"));
	init_variables(engine());
	readfile(av[1]);
	srand(time(NULL));
	engine()->map.coins = create_coins();
	engine()->map.enemies = create_enemies();
	init_window();
	create_new_img();
	set_images();
	engine()->map.player.curr_frame = engine()->map.player.standing[0];
	mlx_loop_hook(engine()->mlx_connect, update, NULL);
	mlx_hook(engine()->mlx_win, 02, 1L<<0, move_handle, NULL);
	mlx_hook(engine()->mlx_win, 03, 1L<<1, reset_handle, NULL);
	mlx_hook(engine()->mlx_win, 17, 1L<<2, close_window, NULL);
	mlx_loop(engine()->mlx_connect);	
}

	// while(i <= engine()->map.map_heigth)
	// {
	// 		printf("%s", engine()->map.map_grid[i]);
	// 	i++;
	// }