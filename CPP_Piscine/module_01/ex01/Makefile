# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 16:55:51 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/26 16:02:11 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= zombies

SRCS := main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

OBJS := $(SRCS:.cpp=.o)

CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
.PHONY : all clean fclean re