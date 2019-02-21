/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_mix_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 12:10:03 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("50 - 45 * 14 % 2");
	n = pop_num();
	ft_printf("50\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("20 - 99 / (96 - 30 * (57 - 76) - 43 % 20) - 17");
	n = pop_num();
	ft_printf("3\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-92");
	n = pop_num();
	ft_printf("-92\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-0");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-2345 + 90");
	n = pop_num();
	ft_printf("-2255\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("20+19*(13+59/(6+4)-97%11)-76");
	n = pop_num();
	ft_printf("115\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("86      -47            *(-26-75/(47-98/23)+17/(-         86  +          44*38))");
	n = pop_num();
	ft_printf("1355\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("(1+ (((((1))))) / 2 *(323/32)*1)--1*1");
	n = pop_num();
	ft_printf("2\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);	

	parse_expr("(1-2*023/1 + (9*2)%5+(12)-1123*(3-5)) + -0");
	n = pop_num();
	ft_printf("2216\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("1- 2 * 2 + 2 / 2 + (1+2 )*2 %1 -(123 * 23 -4)");
	n = pop_num();
	ft_printf("-2827\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	return (0);
}
