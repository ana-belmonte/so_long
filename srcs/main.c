/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:27:45 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/07 16:58:52 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// deltatime = time that passed between two events, 
//in animation keeps everything flow well
// by controling the time and velocity between them 
// keeps value of last call until program ends!!!!
// reset the time

#include <so_long.h>

t_game	*engine(void)
{
	static t_game	game;

	return (&game);
}

void	init_window(int w, int h)
{
	char	*name;
	void	*mlx_cnt;

	engine()->mlx_cnt = mlx_init();
	if (!engine()->mlx_cnt)
		exit(exit_free("fail connecting to interface\n"));
	name = "cacosidade";
	mlx_cnt = engine()->mlx_cnt;
	(engine()->mlx_win) = mlx_new_window(mlx_cnt, w * 64, h * 64, name);
	if (!engine()->mlx_win)
		exit(exit_free("fail initing window\n"));
}

void	create_new_img(int h)
{
	int		*bpp;
	int		*len;
	int		*end;
	void	*img;
	int		w;

	w = engine()->map.w * 64;
	len = &engine()->w_img.line_length;
	bpp = &engine()->w_img.bpp;
	end = &engine()->w_img.endian;
	(engine()->w_img.img) = mlx_new_image(engine()->mlx_cnt, w, h * 64);
	if (!engine()->w_img.img)
		exit(exit_free("fail initing image\n"));
	img = engine()->w_img.img;
	(engine()->w_img.address) = mlx_get_data_addr(img, bpp, len, end);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (exit_free("invalid number of args\n"));
	if (checker_arg(av[1]))
		return (exit_free("invalid args\n"));
	init_variables(engine());
	readfile(av[1]);
	srand(time(NULL));
	engine()->map.coins = create_coins();
	engine()->map.enemies = create_enemies();
	init_window(engine()->map.w, engine()->map.h);
	create_new_img(engine()->map.h);
	set_images();
	engine()->map.player.curr_frame = engine()->map.player.standing[0];
	mlx_loop_hook(engine()->mlx_cnt, update, NULL);
	mlx_hook(engine()->mlx_win, 02, 1L << 0, move_handle, NULL);
	mlx_hook(engine()->mlx_win, 03, 1L << 1, reset_handle, NULL);
	mlx_hook(engine()->mlx_win, 17, 1L << 2, close_window, NULL);
	mlx_loop(engine()->mlx_cnt);
}
