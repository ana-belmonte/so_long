/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:58:41 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/26 16:46:00 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void set_images()
{
 	engine()->map.textures.wall = new_file_image("images/wall.xpm");
	if(!engine()->map.textures.wall.img )
		exit(exit_free("problem creating image"));
	engine()->map.textures.exit = new_file_image("images/exit.xpm");
	if(!engine()->map.textures.exit.img )
		exit(exit_free("problem creating image"));
	// engine()->map.player.sprite[0] = new_file_image("images/front1.xpm");
	// if(!engine()->map.player.sprite[0].img)
	// 	exit(exit_free("problem creating image"));
	// engine()->map.player.sprite[1] = new_file_image("images/left1.xpm");
	// if(!engine()->map.player.sprite[1].img)
	// 	exit(exit_free("problem creating image"));
	// engine()->map.player.sprite[2] = new_file_image("images/rigth1.xpm");
	// if(!engine()->map.player.sprite[2].img)
	// 	exit(exit_free("problem creating image"));
	// //engine()->map.player.sprite[3] = new_file_image("images/back1.xpm");
	// if(!engine()->map.player.sprite[3].img)
	// 	exit(exit_free("problem creating image"));
	
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

void cpy_to_win_image(t_image *base, t_image *old, int sx, int sy)
{
	int y;
	int x;
	
	x = 0;
	while(x < old->width)
	{
		y = 0;
		while(y < old->height)
		{
			cpy_pixel(base, x + sx, y + sy, get_pixel_color(old, x, y));
			y++;
		}
		x++;
	}
	//mlx_put_image_to_window(engine()->mlx_connect, engine()->mlx_win, base->img, 0, 0);	
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