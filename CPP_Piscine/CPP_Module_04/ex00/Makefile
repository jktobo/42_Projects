# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 18:22:03 by dkaratae          #+#    #+#              #
#    Updated: 2023/06/11 18:22:05 by dkaratae         ###   ########.fr        #
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