# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 22:24:46 by Zexi Wang         #+#    #+#              #
#    Updated: 2019/02/12 15:10:08 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bnc

SRCS = srcs/convert.c
INCS = -I incs -I libs/libft/incs
LIBS = libs/libft/libft.a

all:
	gcc -o $(NAME) $(SRCS) $(LIBS) $(INCS)

fclean:
	rm -rf $(NAME)

re: fclean all
