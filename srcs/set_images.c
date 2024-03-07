/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:58:41 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 16:42:49 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	img_help(void *img)
{
	if (!img)
		exit(exit_free("problem creating image"));
}

void	set_images(void)
{
	engine()->map.t_textures.wall = new_file_image("images/wall.xpm");
	img_help(engine()->map.t_textures.wall.img);
	engine()->map.t_textures.exit = new_file_image("images/exit.xpm");
	img_help(engine()->map.t_textures.exit.img);
	engine()->map.player.standing[0] = new_file_image("images/oi/front1.xpm");
	img_help(engine()->map.player.standing[0].img);
	engine()->map.player.standing[1] = new_file_image("images/oi/left1.xpm");
	img_help(engine()->map.player.standing[1].img);
	engine()->map.player.standing[2] = new_file_image("images/oi/rigth1.xpm");
	img_help(engine()->map.player.standing[2].img);
	engine()->map.player.standing[3] = new_file_image("images/oi/back1.xpm");
	img_help(engine()->map.player.standing[3].img);
	engine()->map.t_textures.floor = new_file_image("images/floor.xpm");
	img_help(engine()->map.t_textures.floor.img);
	set_sprite_coins();
	set_sprite_enemies();
	set_animation();
}

void	set_coins(int i)
{
	engine()->map.coins[i].sprite[0] = new_file_image("images/coin1.xpm");
	if (!engine()->map.coins[i].sprite[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.coins[i].sprite[1] = new_file_image("images/coin2.xpm");
	if (!engine()->map.coins[i].sprite[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.coins[i].sprite[2] = new_file_image("images/coin3.xpm");
	if (!engine()->map.coins[i].sprite[2].img)
		exit(exit_free("problem creating image"));
	engine()->map.coins[i].sprite[3] = new_file_image("images/coin4.xpm");
	if (!engine()->map.coins[i].sprite[3].img)
		exit(exit_free("problem creating image"));
}

void	set_enemies(int i)
{
	engine()->map.enemies[i].sprite[0] = new_file_image("images/enemie1.xpm");
	img_help(engine()->map.enemies[i].sprite[0].img);
	engine()->map.enemies[i].sprite[1] = new_file_image("images/enemie2.xpm");
	img_help(engine()->map.enemies[i].sprite[1].img);
	engine()->map.enemies[i].sprite[2] = new_file_image("images/enemie3.xpm");
	img_help(engine()->map.enemies[i].sprite[2].img);
	engine()->map.enemies[i].sprite[3] = new_file_image("images/enemie4.xpm");
	img_help(engine()->map.enemies[i].sprite[3].img);
	engine()->map.enemies[i].sprite[4] = new_file_image("images/enemie5.xpm");
	img_help(engine()->map.enemies[i].sprite[4].img);
	engine()->map.enemies[i].sprite[5] = new_file_image("images/enemie6.xpm");
	img_help(engine()->map.enemies[i].sprite[5].img);
	engine()->map.enemies[i].sprite[6] = new_file_image("images/enemie7.xpm");
	img_help(engine()->map.enemies[i].sprite[6].img);
	engine()->map.enemies[i].sprite[7] = new_file_image("images/enemie8.xpm");
	img_help(engine()->map.enemies[i].sprite[7].img);
	engine()->map.enemies[i].sprite[8] = new_file_image("images/enemie9.xpm");
	img_help(engine()->map.enemies[i].sprite[8].img);
	engine()->map.enemies[i].sprite[9] = new_file_image("images/enemie10.xpm");
	img_help(engine()->map.enemies[i].sprite[9].img);
}

void	set_animation(void)
{
	engine()->map.player.front[0] = new_file_image("images/oi/front2.xpm");
	if (!engine()->map.player.front[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.front[1] = new_file_image("images/oi/front3.xpm");
	if (!engine()->map.player.front[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.left[0] = new_file_image("images/oi/left2.xpm");
	if (!engine()->map.player.left[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.left[1] = new_file_image("images/oi/left3.xpm");
	if (!engine()->map.player.left[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.rigth[0] = new_file_image("images/oi/rigth2.xpm");
	if (!engine()->map.player.rigth[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.rigth[1] = new_file_image("images/oi/rigth3.xpm");
	if (!engine()->map.player.rigth[1].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.back[0] = new_file_image("images/oi/back2.xpm");
	if (!engine()->map.player.back[0].img)
		exit(exit_free("problem creating image"));
	engine()->map.player.back[1] = new_file_image("images/oi/back3.xpm");
	if (!engine()->map.player.back[1].img)
		exit(exit_free("problem creating image"));
}
