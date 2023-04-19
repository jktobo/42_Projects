# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:37:27 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/19 10:07:48 by joldosh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= megaphone

SRCS := main.cpp \
		Contact.cpp \
		Phonebook.cpp \

INCLUDES := Contact.hpp \
			Phonebook.hpp \

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