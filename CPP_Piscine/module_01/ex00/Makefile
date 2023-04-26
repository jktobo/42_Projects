# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 16:53:56 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/26 16:01:57 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= zombie

SRCS := main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \

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
