/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:08:51 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/06 18:11:43 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	endgame(void)
{
	if (engine()->map.c_count == 0 && 
		(int)engine()->map.player.pos_x == engine()->map.e_pos_x 
		&& (int)engine()->map.player.pos_y == engine()->map.e_pos_y)
		exit(exit_free("YOU WON <3\n"));
}
