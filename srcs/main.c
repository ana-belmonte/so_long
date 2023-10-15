/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:27:45 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/13 15:17:56 by aaires-b         ###   ########.fr       */
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
	
	// mlx_xpm_file_to_image;
	// mlx_put_image_to_window;
	//mlx_loop(game->mlx_connect);
}
