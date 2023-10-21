/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:27 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/20 14:27:34 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


t_image *assets(int x, int y)
{
	//if(engine()->map.map_grid[x][y] == 'P')
		//return(engine()->map.textures.player)
	if(engine()->map.map_grid[x][y] == 'E' )
		return(engine()->map.textures.exit);
	//if(engine()->map.map_grid[x][y] == 'C' )
		//return(engine()->map.textures.collect);
	if(engine()->map.map_grid[x][y] == '1' )
		return(&engine()->map.textures.wall);
	//if(engine()->map.map_grid[x][y] == '0' )
		//return(&engine()->map.textures.floor);
	return(NULL);
}

void set_new_image()
{	
	int x;
	int y;	 

	x = 0;
	while(engine()->map.map_grid[x])
	{
		y = 0;
		while(engine()->map.map_grid[x][y] && engine()->map.map_grid[x][y] != '\n')
		{
			if(assets(x, y))
			{
				cpy_to_win_image(engine()->win_image, assets(x, y), x, y);
			}
			y++;
		}
		x++;
	}
}