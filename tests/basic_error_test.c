/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_error_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 12:15:05 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("50 - (40");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("20 - 99 / (96 - 30 * (57 - 76) - --43 % 20) - 17");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("1+-+1");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("++++-0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("-2234 ----");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("20+19*(13+59/(6+4)-97%)-76");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("123 + 234 / 2a");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("1 / -0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);	

	parse_expr("-1 / +0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("-199 / 0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("-1 % +0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("1 % -0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("-1 % 1 / +0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	parse_expr("0 % 1 % 0");
	n = pop_num();
	ft_printf("invalid\n");
	print_num(n); ft_printf("error\n");
	delete_num(&n);

	return (0);
}
