# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 16:17:16 by dkaratae          #+#    #+#              #
#    Updated: 2023/03/09 20:01:17 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wextra -Wall -Werror -pthread #-fsanitize=thread
# CFLAGS = -Wextra -Wall -Werror -fsanitize=thread

PHILO = philo

FILES = 	philo.c \
			philo_utils.c \
			parce.c \
			time.c \
			init.c \
			check.c \

OBJS	=	$(FILES:%c=%o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(PHILO)

$(PHILO) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PHILO)
	
clean :
	rm -f *.o
fclean : clean
	rm -rf $(PHILO)

re : fclean all

.PHONY: all clean fclean re