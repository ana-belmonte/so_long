/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:54:07 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/06 18:24:32 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	close_window(t_game *game)
{
	(void) game;
	exit(exit_free("BYE bItCh!\n"));
}

int	move_handle(int keysym)
{
	if (keysym == 65307)
		exit(exit_free("BYE bItCh!\n"));
	if (keysym == 97 || keysym == 65361)
	{
		engine()->map.player.dir_x = -1;
		engine()->map.player.cur_sprite = engine()->map.player.left;
	}
	if (keysym == 119 || keysym == 65362)
	{
		engine()->map.player.dir_y = -1;
		engine()->map.player.cur_sprite = engine()->map.player.back;
	}
	if (keysym == 100 || keysym == 65363)
	{
		engine()->map.player.dir_x = 1;
		engine()->map.player.cur_sprite = engine()->map.player.rigth;
	}
	if (keysym == 115 || keysym == 65364)
	{
		engine()->map.player.dir_y = 1;
		engine()->map.player.cur_sprite = engine()->map.player.front;
	}
	return (0);
}

int	reset_handle(int keysym)
{
	if (keysym == 97 || keysym == 65361)
	{
		engine()->map.player.dir_x = 0;
		engine()->map.player.curr_frame = engine()->map.player.standing[1];
	}
	if (keysym == 100 || keysym == 65363)
	{
		engine()->map.player.dir_x = 0;
		engine()->map.player.curr_frame = engine()->map.player.standing[2];
	}
	if (keysym == 119 || keysym == 65362)
	{
		engine()->map.player.dir_y = 0;
		engine()->map.player.curr_frame = engine()->map.player.standing[3];
	}
	if (keysym == 115 || keysym == 65364)
	{
		engine()->map.player.dir_y = 0;
		engine()->map.player.curr_frame = engine()->map.player.standing[0];
	}
	return (0);
}
