# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 01:37:30 by dkaratae          #+#    #+#              #
#    Updated: 2022/10/23 20:57:06 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g3

CFLAGS = -Wextra -Wall -Werror

SO_LONG = so_long

SO_LONG_B = so_long_bonus

FILES = ./mandatory/so_long.c \
		./mandatory/map.c \
		./mandatory/check_elements.c \
		./mandatory/ft_put_image.c \
		./mandatory/move.c \

FILES_B = ./bonus/so_long_b.c \
		./bonus/map_b.c \
		./bonus/check_elements_b.c \
		./bonus/ft_put_image_b.c \
		./bonus/move_b.c \
		
OPENGL_PATH = ./mlx/
LIBX = $(OPENGL_PATH)libmlx.a
MLX = $(OPENGL_PATH)libmlx.a -framework OpenGL
APPKIT = -framework AppKit
MLX_FLAGS = $(MLX) $(APPKIT)

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

OBJS	=	$(FILES:%c=%o)
OBJS_B	=	$(FILES_B:%c=%o)

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

all : $(SO_LONG)

bonus : $(SO_LONG_B)

$(SO_LONG) : $(OBJS) $(LIBX) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(SO_LONG)

$(SO_LONG_B) : $(OBJS_B) $(LIBX) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_B) $(LIBFT) $(FT_PRINTF) -o $(SO_LONG_B)

$(LIBX) :
	make -C ./mlx

$(LIBFT):
	make -C libft

$(FT_PRINTF) :
	make -C ft_printf

clean :
	rm -f ./mandatory/*.o
	rm -f ./bonus/*.o
	make clean -C libft

fclean : clean
	make -C ./mlx clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(SO_LONG) $(SO_LONG_B)

re : fclean all bonus

.PHONY: all bonus clean fclean re