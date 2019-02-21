/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_add_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 11:54:55 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("1333 + 1000");
	n = pop_num();
	ft_printf("2333\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("123 + 902834");
	n = pop_num();
	ft_printf("902957\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-2345 + -90");
	n = pop_num();
	ft_printf("-2435\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-23 + -9090909");
	n = pop_num();
	ft_printf("-9090932\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-2345 + 90");
	n = pop_num();
	ft_printf("-2255\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-111 + 4243");
	n = pop_num();
	ft_printf("4132\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("999 + -89");
	n = pop_num();
	ft_printf("910\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("1 + -100000");
	n = pop_num();
	ft_printf("-99999\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);	

	parse_expr("-0 + 0000000000 + 0 + 0 - 0");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("0 + -1");
	n = pop_num();
	ft_printf("-1\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("11111111111111 + 11111111111111");
	n = pop_num();
	ft_printf("22222222222222\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("111111111111 + -    11111111111111");
	n = pop_num();
	ft_printf("-11000000000000\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-       1234567890  \n  + -0987654321");
	n = pop_num();
	ft_printf("-2222222211\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	return (0);
}
