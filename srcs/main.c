/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:27:45 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/21 20:29:43 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_game *engine()
{
	static t_game game;
	
	return (&game);
}

update_player_pos()
{

	//player_x += delta_time * dir_x * velocidade;
}

void update_delta_time() // deltatime = time that passed between two events, in animation keeps everything flow well by controling the time and velocity between then 
{
	static struct timeval last_time; // keeps value of last call until program ends!!!!
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	engine()->delta_time = (current_time.tv_sec - last_time.tv_sec) +
						(current_time.tv_usec - last_time.tv_usec) / 1000000.0
	last_time = current_time; // reset the time
}

void render_player()
{
	print_image(32 * player_x, 64 * player_y)
}

int update()
{
	update_delta_time();
	//update_player_pos();
	//render_map();
	//render_player()
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if(ac != 2)
		return (exit_free("invalid number of args\n"));
	if(checker_arg(av[1]))
		return(exit_free("invalid args\n"));
	init_variables(engine());
	readfile(av[1]);
	init_window();
	if(!engine()->mlx_connect)
		exit(exit_free("fail connecting to interface\n"));
	engine()->mlx_win = mlx_new_window(engine()->mlx_connect, engine()->map.map_width * 64, engine()->map.map_heigth * 64, "cacosidade");
	if(!engine()->mlx_win)
		exit(exit_free("fail initing window\n"));
	engine()->win_image.img = mlx_new_image(engine()->mlx_connect, engine()->map.map_width * 64, engine()->map.map_heigth * 64);
	if(!engine()->win_image.img)
		exit(exit_free("fail initing image\n"));
	engine()->win_image.address = mlx_get_data_addr(engine()->win_image.img, &engine()->win_image.bpp, &engine()->win_image.line_length, &engine()->win_image.endian);
	set_image();
	set_new_image();
	// mlx_put_image_to_window(engine()->mlx_connect, engine()->mlx_win, engine()->win_image.img, 0, 0);
	mlx_hook(engine()->mlx_win, 02, 1L<<0, move_handle, NULL);
	mlx_hook(engine()->mlx_win, 03, 1L<<1, reset_handle, NULL);
	mlx_hook(engine()->mlx_win, 17, 1L<<2, close_window, NULL);
	mlx_look_hook(engine()->mlx_connect, update, NULL);
	mlx_key_hook(engine()->mlx_win, escape, engine());
	mlx_loop(engine()->mlx_connect);
}

// while(i <= engine()->map.map_heigth)
// {
// 		printf("%s", engine()->map.map_grid[i]);
//   	i++;
// }