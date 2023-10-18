/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:27:45 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/18 17:03:33 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_game *engine()
{
	static t_game game;
	
	return (&game);
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
	engine()->mlx_connect = mlx_init();
	if(!engine()->mlx_connect)
		exit(exit_free("fail connecting to interface"));
	engine()->mlx_win = mlx_new_window(engine()->mlx_connect, engine()->map.map_width  * 64, engine()->map.map_heigth * 64, "cacosidade");
	if(!engine()->mlx_win)
		exit(exit_free("fail initing window\n"));
	set_image();
	render_map();
	mlx_hook(engine()->mlx_win, 02, 1L<<0, move_handle, NULL);
	mlx_hook(engine()->mlx_win, 17, 1L<<2, close_window, NULL);
	mlx_key_hook(engine()->mlx_win, escape, engine());
	mlx_loop(engine()->mlx_connect);
}

// while(i <= engine()->map.map_heigth)
// {
// 		printf("%s", engine()->map.map_grid[i]);
//   	i++;
// }