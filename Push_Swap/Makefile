# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:59:48 by dkaratae          #+#    #+#              #
#    Updated: 2022/12/28 16:02:41 by dkaratae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wextra -Wall -Werror 

PUSH_SWAP = push_swap

CHECKER = checker

FILES = 	./mandatory/push_swap.c \
			./mandatory/ft_parcing_int.c \
			./mandatory/ft_parcing_char.c \
			./mandatory/ft_list.c \
			./mandatory/ft_sort_three_elem.c \
			./mandatory/ft_rules.c \
			./mandatory/ft_push.c \
			./mandatory/ft_sort_full_elem.c \
			./mandatory/ft_free.c \
			./mandatory/ft_calculate.c \
		
FILES_B = 	./bonus/checker.c \
			./bonus/ft_parcing_int_b.c \
			./bonus/ft_parcing_char_b.c \
			./bonus/ft_parcing_char2_b.c \
			./bonus/ft_list_b.c \
			./bonus/ft_rules2_b.c \
			./bonus/ft_rules_b.c \
			./bonus/ft_push_b.c \
			./bonus/ft_free_b.c \

LIBFT = libft/libft.a

OBJS	=	$(FILES:%c=%o)
OBJS_B	=	$(FILES_B:%c=%o)

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

all : $(PUSH_SWAP)

bonus : $(CHECKER)

$(PUSH_SWAP) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(PUSH_SWAP)
	
$(CHECKER) : $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(CHECKER)

$(LIBFT):
	make -C libft

clean :
	rm -f ./mandatory/*.o
	rm -f ./bonus/*.o
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -rf $(PUSH_SWAP) $(CHECKER)

re : fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus