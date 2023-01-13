# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 17:19:43 by dkaratae          #+#    #+#              #
#    Updated: 2022/08/19 15:20:33 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

SERVER = server

CLIENT = client

SERVER_B = server_b

CLIENT_B = client_b

all :
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) server.c ft_printf/libftprintf.a -o $(SERVER)
	$(CC) $(CFLAGS) client.c libft/libft.a ft_printf/libftprintf.a -o $(CLIENT)

bonus :
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) server_bonus.c ft_printf/libftprintf.a -o $(SERVER_B)
	$(CC) $(CFLAGS) client_bonus.c libft/libft.a ft_printf/libftprintf.a -o $(CLIENT_B)
clean :
	make clean -C libft 
	make clean -C ft_printf 
	rm -rf client.o server.o server_bonus.o client_bonus.o

fclean : clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re : fclean all