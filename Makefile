# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 22:24:46 by Zexi Wang         #+#    #+#              #
#    Updated: 2019/02/24 10:20:31 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bnc
CFLAG = -Wall -Wextra -Werror

INTERFACE = apply.c expr.c numstack.c opstack.c compute.c
CORE = numpart.c convert.c bignum.c add.c subtract.c compo.c shift.c \
	   multiply.c numinfo.c divide.c modulo.c exponent.c
MAIN = srcs/bnc.c

INTERFACE_DIR = ./srcs/interface/
CORE_DIR = ./srcs/core/

SRCS = $(addprefix $(INTERFACE_DIR), $(INTERFACE)) \
	   $(addprefix $(CORE_DIR), $(CORE))
INCS = -I incs -I libs/libft/incs
LIBS = libs/libft/libft.a

all:
	@gcc $(CFLAG) -o $(NAME) $(MAIN) $(SRCS) $(LIBS) $(INCS)

test1:
	@gcc -o test1.out tests/basic_add_test.c $(SRCS) $(LIBS) $(INCS)
	@./test1.out
	@rm -rf test1.out

test2:
	@gcc -o test2.out tests/basic_subtract_test.c $(SRCS) $(LIBS) $(INCS)
	@./test2.out
	@rm -rf test2.out

test3:
	@gcc -o test3.out tests/basic_multiply_test.c $(SRCS) $(LIBS) $(INCS)
	@./test3.out
	@rm -rf test3.out

test4:
	@gcc -o test4.out tests/basic_divide_test.c $(SRCS) $(LIBS) $(INCS)
	@./test4.out
	@rm -rf test4.out

test5:
	@gcc -o test5.out tests/basic_modulo_test.c $(SRCS) $(LIBS) $(INCS)
	@./test5.out
	@rm -rf test5.out

test6:
	@gcc -o test6.out tests/basic_mix_test.c $(SRCS) $(LIBS) $(INCS)
	@./test6.out
	@rm -rf test6.out

test7:
	@gcc -o test7.out tests/basic_error_test.c $(SRCS) $(LIBS) $(INCS)
	@./test7.out
	@rm -rf test7.out


fclean:
	@rm -rf $(NAME)

re: fclean all
