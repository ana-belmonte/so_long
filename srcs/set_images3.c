/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:42:30 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 18:39:36 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	set_sprite_enemies(void)
{
	int	i;

	i = 0;
	while (i < engine()->map.monster_c)
	{
		set_enemies(i);
		i++;
	}
}

void	set_sprite_coins(void)
{
	int	i;

	i = 0;
	while (i < engine()->map.c_count)
	{
		set_coins(i);
		i++;
	}
}
