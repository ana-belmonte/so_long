/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:08:51 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 15:05:51 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void endgame()
{
	// printf("c_count :%d\n",engine()->map.c_count);
	// printf("player pos_x :%f\n",engine()->map.player.pos_x);
	// printf("exit pos_x :%d\n",engine()->map.e_pos_x);
	// printf("player pos_y :%f\n",engine()->map.player.pos_y);
	// printf("exit pos_y :%d\n",engine()->map.e_pos_y);
	if(engine()->map.c_count == 0 && (int)engine()->map.player.pos_x == engine()->map.e_pos_x 
		&& (int)engine()->map.player.pos_y == engine()->map.e_pos_y)
		exit(exit_free("YOU WON <3\n"));
}