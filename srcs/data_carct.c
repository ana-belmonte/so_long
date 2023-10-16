/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_carct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:44:18 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/15 15:48:54 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int data_caract(char **newmap)
{
	int x;
	int y;

	x = 0;
	while(newmap[x])
	{
		y = 0;
		while(newmap[x][y])
		{
			if(newmap[x][y] == 'E' || newmap[x][y] == 'C')
				return(1);
			y++;
		}
		x++;
	}
	return(0);
}