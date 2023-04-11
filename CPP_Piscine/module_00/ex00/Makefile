# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 08:10:30 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/09 16:26:17 by joldosh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= megaphone

SRCS := megaphone.cpp

# INCLUDES := 

OBJS := $(SRCS:,cpp=.o)

CC := c++
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
