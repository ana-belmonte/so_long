/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:38:57 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/14 16:10:53 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mlx.h"
#include <string.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct s_texture
{
	void *player;
	void *collect;
	void *exit;
	void *enemies;
	void *wall;
} t_texture;

typedef struct s_map_data
{
	char **map_grid;
	int map_heigth;
	int map_width;
	int c_count;
	int p_pos_x;
	int p_pos_y;
	t_texture textures;
} t_map_data;

typedef struct s_game
{
	t_map_data map;
	void *mlx_connect;
	void *mlx_win;
	int win_heigth;
	int win_width;

} t_game;


// MAP RELATED

void	readfile(char *filename);
char	*get_next_line(int fd);
int		create_map(char *filename, int fd);

// ERROR HANDLING

int	exit_free(char *error);
int	checker_arg(char *arg);
int checker_map();

// MAIN STRUCT

t_game	*engine();
void	init_variables(t_game *game);

#endif