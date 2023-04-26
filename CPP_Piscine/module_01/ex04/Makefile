# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 17:03:52 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/26 16:02:37 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= losers

SRCS := main.cpp \
		
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