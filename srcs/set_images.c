/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:58:41 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 14:47:04 by aaires-b         ###   ########.fr       */
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
	engine()->map.player.standing[0] = new_file_image("images/oi/front1.xpm");
	if(!engine()->map.player.standing[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.standing[1] = new_file_image("images/oi/left1.xpm");
	if(!engine()->map.player.standing[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.standing[2] = new_file_image("images/oi/rigth1.xpm");
	if(!engine()->map.player.standing[2].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.standing[3] = new_file_image("images/oi/back1.xpm");
	if(!engine()->map.player.standing[3].img)
		exit(exit_free("problem creating image"));
	engine()->map.textures.floor = new_file_image("images/floor.xpm");
	if(!engine()->map.textures.floor.img)
		exit(exit_free("problem creating image"));
	set_sprite_coins();
	set_sprite_enemies();
	set_animation();
}

void set_sprite_enemies()
{
	int i;

	i = 0;
	while(i < engine()->map.monster_c)
	{
		set_enemies(i);
		i++;
	}
}
void set_sprite_coins()
{
	int i;

	i = 0;
	while(i < engine()->map.c_count)
	{
		set_coins(i);
		i++;
	}
}
void set_coins(int i)
{
	engine()->map.coins[i].sprite[0] = new_file_image("images/coin1.xpm");
	if(!engine()->map.coins[i].sprite[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.coins[i].sprite[1] = new_file_image("images/coin2.xpm");
	if(!engine()->map.coins[i].sprite[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.coins[i].sprite[2] = new_file_image("images/coin3.xpm");
	if(!engine()->map.coins[i].sprite[2].img)
		exit(exit_free("problem creating image"));
	engine()->map.coins[i].sprite[3] = new_file_image("images/coin4.xpm");
	if(!engine()->map.coins[i].sprite[3].img)
		exit(exit_free("problem creating image"));	
}

void set_enemies(int i)
{
	engine()->map.enemies[i].sprite[0] = new_file_image("images/enemie1.xpm");
	if(!engine()->map.enemies[i].sprite[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[1] = new_file_image("images/enemie2.xpm");
	if(!engine()->map.enemies[i].sprite[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[2] = new_file_image("images/enemie3.xpm");
	if(!engine()->map.enemies[i].sprite[2].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[3] = new_file_image("images/enemie4.xpm");
	if(!engine()->map.enemies[i].sprite[3].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[4] = new_file_image("images/enemie5.xpm");
	if(!engine()->map.enemies[i].sprite[4].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[5] = new_file_image("images/enemie6.xpm");
	if(!engine()->map.enemies[i].sprite[5].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[6] = new_file_image("images/enemie7.xpm");
	if(!engine()->map.enemies[i].sprite[6].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[7] = new_file_image("images/enemie8.xpm");
	if(!engine()->map.enemies[i].sprite[7].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[8] = new_file_image("images/enemie9.xpm");
	if(!engine()->map.enemies[i].sprite[8].img)
		exit(exit_free("problem creating image"));
	engine()->map.enemies[i].sprite[9] = new_file_image("images/enemie10.xpm");
	if(!engine()->map.enemies[i].sprite[9].img)
		exit(exit_free("problem creating image"));
	
}
void set_animation()
{
	engine()->map.player.front[0] = new_file_image("images/oi/front2.xpm");
	if(!engine()->map.player.front[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.front[1] = new_file_image("images/oi/front3.xpm");
	if(!engine()->map.player.front[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.left[0] = new_file_image("images/oi/left2.xpm");
	if(!engine()->map.player.left[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.left[1] = new_file_image("images/oi/left3.xpm");
	if(!engine()->map.player.left[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.rigth[0] = new_file_image("images/oi/rigth2.xpm");
	if(!engine()->map.player.rigth[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.rigth[1] = new_file_image("images/oi/rigth3.xpm");
	if(!engine()->map.player.rigth[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.back[0] = new_file_image("images/oi/back2.xpm");
	if(!engine()->map.player.back[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.back[1] = new_file_image("images/oi/back3.xpm");
	if(!engine()->map.player.back[1].img)
		exit(exit_free("problem creating image"));
	
}

// t_image *rescale_img(t_image *old_image, int scale)
// {
// 	t_image *image;
	
// 	image.img = mlx_new_image(engine()->mlx_connect, old_image->width * scale, old_image->heigth * scale);
// 	if(!image.img)
// 		exit_free("problem creating image");
// 	image.address = mlx_get_data_addr(engine()->win_image.img, &engine()->win_image.bpp, &engine()->win_image.line_length, &engine()->win_image.endian);
// 	return(image);
// }

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