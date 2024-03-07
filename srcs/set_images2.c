/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:41:12 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 16:41:38 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_image	new_file_image(char *path)
{
	t_image	image;

	image.img = mlx_xpm_file_to_image(engine()->mlx_cnt, path, 
			&image.width, &image.height);
	if (!image.img)
		exit(exit_free("problem creating image"));
	image.address = mlx_get_data_addr(image.img, &image.bpp, 
			&image.line_length, &image.endian);
	return (image);
}

void	cpy_to_win_image(t_image *base, t_image *old, int sx, int sy)
{
	int	y;
	int	x;

	x = 0;
	while (x < old->width)
	{
		y = 0;
		while (y < old->height)
		{
			cpy_pixel(base, x + sx, y + sy, get_pixel_color(old, x, y));
			y++;
		}
		x++;
	}
}

void	cpy_pixel(t_image *base, int x, int y, unsigned int color)
{
	char	*dst;

	if (color == (unsigned int)0xff000000)
		return ;
	dst = base->address + (y * base->line_length + x * (base->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_image *old, int x, int y)
{
	char	*dst;

	dst = old->address + (y * old->line_length + x * (old->bpp / 8));
	return (*(unsigned int *)dst);
}
