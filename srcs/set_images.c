/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 05:39:22 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/19 20:04:24 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void set_image()
{
 	engine()->map.textures.wall = new_file_image("images/floor.xpm");
	engine()->map.textures.floor = new_file_image("images/floor2.xpm");
	if(!engine()->map.textures.wall.img || !engine()->map.textures.floor.img)
		exit(exit_free("problem creating image"));
	// mlx_put_image_to_window(engine()->mlx_connect, engine()->mlx_win, engine()->map.textures.wall.img, 0, 0);
	// mlx_put_image_to_window(engine()->mlx_connect, engine()->mlx_win, engine()->map.textures.floor.img, 64*2, 64*2);
	cpy_to_win_image(&engine()->win_image, engine()->map.textures.wall, 0, 0);
	// cpy_to_win_image(&engine()->win_image, engine()->map.textures.floor, 10, 100);
}

t_image new_file_image(char *path)
{
	t_image image;

	image.img = mlx_xpm_file_to_image(engine()->mlx_connect, path, &image.width, &image.height);
	if(!image.img)
		exit(exit_free("problem creating image"));
	image.address = mlx_get_data_addr(image.img, &image.bpp, &image.line_length, &image.endian);
	return(image);
}

void cpy_to_win_image(t_image *base, t_image old, int x, int y)
{
	int i;
	int j;
	
	i = 0;
	printf("Width: %d\n", old.width);
	printf("Height: %d\n", old.height);

	while(i < old.width)
	{
		j = 0;
		while(j < old.height)
		{
			cpy_pixel(base, x + i, y + j, get_pixel_color(&old, i, j));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(engine()->mlx_connect, engine()->mlx_win, base->img, 0, 0);	
}

void cpy_pixel(t_image *base, int x, int y, unsigned int color)
{
	char *dst;

	if(color == (unsigned int)0xff000000)
		return ;
	dst = base->address + (y * base->line_length + x * (base->bpp / 8));
		*(unsigned int *)dst = color;
}

//calculates memory offset
int get_pixel_color(t_image *old, int x, int y)
{
	char *dst;
	dst = old->address + (y * old->line_length + x * (old->bpp / 8));
	// moves the memory location that in on to the block that i wanna go by adding the number of bytes to move foward 
	// line len : number of bytes required to store one row of the image
	//printf("data->bpp = %d\n", (data->bpp));
	return(*(unsigned int *)dst);
}