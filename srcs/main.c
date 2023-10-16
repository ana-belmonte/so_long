/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:27:45 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/15 20:53:51 by aaires-b         ###   ########.fr       */
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
	if(ac != 2)
		return (exit_free("invalid number of args"));
	if(checker_arg(av[1]))
		return(exit_free("invalid args"));
	init_variables(engine());
	readfile(av[1]);
	engine()->mlx_connect = mlx_init();
	engine()->mlx_win = mlx_new_window(engine()->mlx_connect, 1000, 700, "cacosidade");
	if(!engine()->mlx_win)
		return(exit_free("fail initing window"));
	set_images(); //em falta 
	set_events_hooks(); // em falta
	mlx_loop(engine()->mlx_connect);
}
