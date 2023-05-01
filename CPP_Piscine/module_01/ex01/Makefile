# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 16:55:51 by dkaratae          #+#    #+#              #
#    Updated: 2023/05/01 17:15:17 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombies

SRCS 	= main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++
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