# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 12:53:25 by dkaratae          #+#    #+#              #
#    Updated: 2023/05/24 11:51:59 by joldosh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphism

SRCS = main.cpp \
		Animal.cpp \
		WrongAnimal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongCat.cpp \
		
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all