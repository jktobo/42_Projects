# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:37:27 by dkaratae          #+#    #+#              #
#    Updated: 2023/04/15 17:38:54 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= megaphone

SRCS := Contact.cpp \
		Phonebook.cpp \

# INCLUDES := 

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