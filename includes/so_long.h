/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:38:57 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/18 17:20:03 by aaires-b         ###   ########.fr       */
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
#include "../libft/libft.h"
#include "get_next_line.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>


typedef struct s_image
{
	void *img;
	char *address;
	int endian;
	int bpp;
	int line_length;
	
} t_image;

typedef struct s_texture
{
	t_image player;
	t_image collect;
	t_image exit;
	t_image floor;
	t_image wall;
} t_texture;

typedef struct s_map_data
{
	char **map_grid;
	float map_heigth;
	float map_width;
	int	c_count;
	float p_pos_x;
	float p_pos_y;
	t_texture textures;
} t_map_data;

typedef struct s_game
{
	t_map_data map;
	void *mlx_connect;
	void *mlx_win;
	int n_moves;

} t_game;


// MAP RELATED

void	readfile(char *filename);
char	*get_next_line(int fd);
int		create_map(char *filename, int fd);
char  **create_map_cpy();
void render_map();

// ERROR HANDLING

int	exit_free(char *error);
int	checker_arg(char *arg);
int checker_map();
int data_caract(char **newmap);
void free_cpy(char **newmap);

// MAIN STRUCT

t_game	*engine();
void	init_variables(t_game *game);

// EVENT HANDLING

int escape(int keysym);
int close_window(t_game *game);
int move_handle(int keysym);
void set_image();

// MOVES

void move_left();
void move_right();
void move_up();
void move_down();

#endif
