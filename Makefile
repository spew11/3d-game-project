# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunjilee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:58:03 by eunjilee          #+#    #+#              #
#    Updated: 2023/02/02 16:06:12 by eunjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -c
RM = rm -f
AR = ar
CRS = crs
INC_DIR = includes
SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, \
		main.c \
		get_next_line.c \
		get_next_line_utils.c \
		check.c \
		error.c \
		parse.c \
		parse2.c \
		utils.c \
		ft_split.c \
		ft_split_nl.c \
		memory_utils.c \
		parse_utils.c \
		parse_config.c \
		check_map.c \
		queue.c \
		interrupt.c \
		move.c \
		rotate.c \
		parse_player.c \
		ray_init.c \
		draw.c \
		raycast.c \
		parse_img.c \
		bfs_utils.c \
		)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC_DIR) $< -o $@

$(NAME): $(OBJS)
		$(CC) -o $@ $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re
