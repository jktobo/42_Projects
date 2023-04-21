# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 16:57:54 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/21 11:56:26 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= zombies

SRCS := main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

OBJS := $(SRCS:,cpp=.o)

CC := g++
CFLAGS := -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS) Makefile
	$(CC) $(OBJS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME)

re : flclean all
.PHONY : all clean fclean re