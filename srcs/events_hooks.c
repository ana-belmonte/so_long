/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:54:07 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/16 12:38:17 by aaires-b         ###   ########.fr       */
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
		move_left();
	if(keysym  == 119 || keysym  == 65362)
		move_up();
	if(keysym  == 100 || keysym  == 65363)
		move_right();
	if(keysym  == 115 || keysym  == 65364)
		move_down();
	return (0);
}