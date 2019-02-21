/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_multiply_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 10:58:09 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("1333 * 1000");
	n = pop_num();
	ft_printf("1333000\n");
	print_num(n);
	delete_num(&n);

	parse_expr("123 * 11023");
	n = pop_num();
	ft_printf("1355829\n");
	print_num(n);
	delete_num(&n);

	parse_expr("-2345 * -90");
	n = pop_num();
	ft_printf("211050\n");
	print_num(n);
	delete_num(&n);

	parse_expr("-23 * -9090909");
	n = pop_num();
	ft_printf("209090907\n");
	print_num(n);
	delete_num(&n);

	parse_expr("-2345 * 90");
	n = pop_num();
	ft_printf("-211050\n");
	print_num(n);
	delete_num(&n);

	parse_expr("-111 * 4243");
	n = pop_num();
	ft_printf("-470973\n");
	print_num(n);
	delete_num(&n);

	parse_expr("999 * -89");
	n = pop_num();
	ft_printf("-88911\n");
	print_num(n);
	delete_num(&n);

	parse_expr("191 * -100000");
	n = pop_num();
	ft_printf("-19100000\n");
	print_num(n);
	delete_num(&n);	

	parse_expr("-0 * 0000000000 * 0 * 0 * 0");
	n = pop_num();
	ft_printf("0\n");
	print_num(n);
	delete_num(&n);

	parse_expr("0 * -1");
	n = pop_num();
	ft_printf("0\n");
	print_num(n);
	delete_num(&n);

	parse_expr("-1 * 0");
	n = pop_num();
	ft_printf("0\n");
	print_num(n);
	delete_num(&n);

	parse_expr("11111111111111 * 11111111111111");
	n = pop_num();
	ft_printf("123456790123454320987654321\n");
	print_num(n);
	delete_num(&n);

	parse_expr("111111111111 * -    11111111111111");
	n = pop_num();
	ft_printf("-1234567901233320987654321\n");
	print_num(n);
	delete_num(&n);

	parse_expr("-       1234567890  \n  * -0987654321");
	n = pop_num();
	ft_printf("1219326311126352690\n");
	print_num(n);
	delete_num(&n);

	parse_expr("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 * 2");
	n = pop_num();
	ft_printf("2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222\n");
	print_num(n);
	delete_num(&n);
	
	return (0);
}
