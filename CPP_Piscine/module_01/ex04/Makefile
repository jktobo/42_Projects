# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 17:03:52 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/24 13:31:31 by joldosh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= losers

SRCS := main.cpp \
		
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