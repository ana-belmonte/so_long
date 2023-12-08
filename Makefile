# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 12:51:00 by aaires-b          #+#    #+#              #
#    Updated: 2023/11/09 15:30:08 by aaires-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCSFILES = main.c exit_free.c init.c map.c checkers.c get_next_line.c \
			get_next_line_utils.c data_carct.c events_hooks.c \
			set_images.c rendering.c coins.c collision.c endgame.c enemies.c
##PARSFILES = checkers.c

SRCSDIR	= srcs
##PARSDIR = parsing
OBJDIR	= obj
CC = cc 
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LIBFT = libft/libft.a
LIBFTDIR = libft
LIBFTFLAGS = -L ./libft/ -lft
MLX = mlx_linux/libmlx_Linux.a
MLXFLAGS = -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
##MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLXDIR = mlx_linux
INCLUDE = -Iincludes -I/usr/include -Imlx_linux -Ilibft
##INCLUDE = -Iincludes -I/usr/include -Imlx_OS -Ilibft
# SRCS 	= $(addprefix $(SRCSDIR)/, $(SRCSFILES)) $(addprefix $(PARSDIR)/, $(PARSFILES))
# OBJS 	= $(patsubst $(SRCSDIR)/%.c, $(OBJDIR)/%.o, $(SRCS)) $(patsubst $(PARSDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

SRCS	= $(addprefix $(SRCSDIR)/, $(SRCSFILES))

OBJS	= $(patsubst $(SRCSDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all : $(NAME)

## $(NAME): $(OBJ)
## $(CC) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

## $(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR)
## $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MLX): 
	@make -C $(MLXDIR)

$(LIBFT): 
	@make -C $(LIBFTDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean : 
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re
