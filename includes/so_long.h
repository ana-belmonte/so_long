/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:38:57 by aaires-b          #+#    #+#             */
/*   Updated: 2023/11/09 16:35:32 by aaires-b         ###   ########.fr       */
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
#include <sys/time.h>
#include <time.h>

typedef struct s_image
{
	void *img;
	char *address;
	int endian;
	int bpp;
	int line_length;
	int width;
	int height;
	
} t_image;

typedef struct s_player
{
	int dir_x;
	int dir_y;
	float pos_x;
	float pos_y;
	float velocity;
	t_image standing[4];
	t_image left[2];
	t_image front[2];
	t_image rigth[2];
	t_image back[2];
	t_image *cur_sprite;
	t_image curr_frame;
	int curr_frame2;
} t_player;


typedef struct s_coin
{
	float pos_x;
	float pos_y;
	t_image sprite[4];
	int curr_frame;
	int is_collected;

} t_coin;

typedef struct s_textures
{
	t_image wall;
	t_image exit;
	t_image floor;
} textures;

typedef struct s_enemie
{
	t_image sprite[10];
	int pos_x;
	int pos_y;
	float velocity;
	int cur_frame;
} t_enemie;

typedef struct s_map_data
{
	char **map_grid;
	int  map_heigth;
	int map_width;
	int	c_count;
	int monster_c;
	int total_c_count;
	int wall;
	t_player player;
	t_coin *coins;
	t_enemie *enemies;
	textures textures;
	int e_pos_x;
	int e_pos_y;
} t_map_data;

typedef struct s_game
{
	t_map_data map;
	void *mlx_connect;
	void *mlx_win;
	int n_moves;
	t_image win_image;
	float delta_time;
	float velocidade;
} t_game;


// MAP RELATED

void	readfile(char *filename);
char	*get_next_line(int fd);
int		create_map(char *filename, int fd);
char  **create_map_cpy();
void render_map();
void cpy_to_win_image(t_image *base, t_image *old, int x, int y);
void set_animation();
void find_collision();
t_coin *create_coins();
int check_wall_collision(t_map_data map, int new_x, int new_y);
void render_exit();
void endgame();
void enemie_collision();
// ERROR HANDLING

int	exit_free(char *error);
int	checker_arg(char *arg);
int checker_map();
int data_caract(char **newmap);
void free_cpy(char **newmap);

// MAIN STRUCT

t_game	*engine();
void	init_variables(t_game *game);
void init_image(t_image *image);

// EVENT HANDLING

int escape(int keysym);
int close_window(t_game *game);
int move_handle(int keysym);
int update();
void set_images();
void set_coins(int index);
t_image new_file_image(char *path);
int get_pixel_color(t_image *old, int x, int y);
void cpy_pixel(t_image *base, int x, int y, unsigned int color);
int reset_handle(int keysym);
void render_coin();
// MOVES

t_enemie *create_enemies();
void set_sprite_enemies();
void move_left();
void move_right();
void move_up();
void move_down();
void render_player();
void find_coins();
void set_enemies(int i);
void render_enemies();
void collect_coin();
void free_loop_player(t_image *image, int len);
void set_sprite_coins();

#endif
