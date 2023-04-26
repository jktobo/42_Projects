# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 08:10:30 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/26 15:22:48 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= megaphone

SRCS := megaphone.cpp

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
