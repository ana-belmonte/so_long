/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:38:24 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 15:50:04 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render_enemies(void)
{
	static int	curr_frame;
	static int	count;
	int			i;
	int			x;
	int			y;

	i = 0;
	while (i < engine()->map.monster_c)
	{
		if (!(count % 40))
			curr_frame++;
		x = engine()->map.enemies[i].pos_x;
		y = engine()->map.enemies[i].pos_y;
		cpy_to_win_image(&engine()->w_img, 
			&engine()->map.enemies[i].sprite[curr_frame % 10], x * 64, y * 64);
		count++;
		i++;
	}
}

void	render_coin(void)
{
	int			x;
	int			y;
	static int	curr_frame;
	static int	count;
	int			i;

	i = 0;
	while (i < engine()->map.total_c_count)
	{
		if (!engine()->map.coins[i].is_collected)
		{
			if (!(count % 40))
				curr_frame++;
			x = engine()->map.coins[i].pos_x;
			y = engine()->map.coins[i].pos_y;
			cpy_to_win_image(&engine()->w_img, 
				&engine()->map.coins[i].sprite[curr_frame % 4], x * 64, y * 64);
			count++;
		}
		i++;
	}
}
