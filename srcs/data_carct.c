/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_carct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:44:18 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/06 18:10:40 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	data_caract(char **newmap)
{
	int	x;
	int	y;

	y = 0;
	while (newmap[y])
	{
		x = 0;
		while (newmap[y][x])
		{
			if (newmap[y][x] == 'E' || newmap[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
