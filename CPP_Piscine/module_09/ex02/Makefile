# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 16:17:59 by dkaratae          #+#    #+#              #
#    Updated: 2023/11/24 16:29:11 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS = main.cpp \
		PmergeMe.cpp \
		
HEADER = PmergeMe.hpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
$(OBJS): $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all