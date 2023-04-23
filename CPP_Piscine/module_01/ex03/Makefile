# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 16:59:32 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/23 13:01:18 by joldosh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= violence

SRCS := main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		# HumanB.cpp \
		
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