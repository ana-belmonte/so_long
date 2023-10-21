/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:54:07 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/21 20:18:25 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int escape(int keysym)
{
	if(keysym == 65307 || keysym == 1)
		exit(exit_free("BYE bItCh!\n"));
	return(0);
}

int close_window(t_game *game)
{
	(void) game;
	exit(exit_free("BYE bItCh!\n"));
}

int move_handle(int keysym)
{
	if(keysym  == 97 || keysym == 65361)
		engine()->map.player.dir_x = -1;
	if(keysym  == 119 || keysym  == 65362)
		engine()->map.player.dir_y = -1;
	if(keysym  == 100 || keysym  == 65363)
		engine()->map.player.dir_x = 1;
	if(keysym  == 115 || keysym  == 65364)
		engine()->map.player.dir_y = 1;
	return (0);
}

int reset_handle(int keysym)
{
	if(keysym  == 97 || keysym == 65361)
		engine()->map.player.dir_x = 0;
	if(keysym  == 119 || keysym  == 65362)
		engine()->map.player.dir_y = 0;
	if(keysym  == 100 || keysym  == 65363)
		engine()->map.player.dir_x = 0;
	if(keysym  == 115 || keysym  == 65364)
		engine()->map.player.dir_y = 0;
	return (0);
}