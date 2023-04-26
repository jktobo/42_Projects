# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:37:27 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/26 15:26:56 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= phonebook

SRCS := main.cpp \
		Contact.Class.cpp \
		PhoneBook.Class.cpp \

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