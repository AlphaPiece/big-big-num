# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 22:24:46 by Zexi Wang         #+#    #+#              #
#    Updated: 2019/02/11 00:23:06 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bnc

SRCS = srcs/calculate.c srcs/add.c srcs/subtract.c
INCS = -I incs -I libs/libft/incs
LIBS = libs/libft/libft.a

all:
	gcc -o $(NAME) $(SRCS) $(LIBS) $(INCS)

fclean:
	rm -rf $(NAME)

re: fclean all
