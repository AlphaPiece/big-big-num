/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_modulo_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 12:09:26 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("10293840148032 % 12424214");
	n = pop_num();
	ft_printf("6122612\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("1234 % 2348104823");
	n = pop_num();
	ft_printf("1234\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-12983424 % -294324");
	n = pop_num();
	ft_printf("-33168\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-234 % -009238434");
	n = pop_num();
	ft_printf("-234\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-1240238402 % 932");
	n = pop_num();
	ft_printf("-838\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-12498 % 2042033434");
	n = pop_num();
	ft_printf("-12498\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("2314018203582 % -2348");
	n = pop_num();
	ft_printf("2218\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("1029 % -224234242");
	n = pop_num();
	ft_printf("1029\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);	

	parse_expr("0 % -1");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-0 % 1");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("111111111111111111111111111 % 1111111111111111111");
	n = pop_num();
	ft_printf("11111111\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("9217498274485281803582741729512323894724784242 % 1294724789274892742749234234");
	n = pop_num();
	ft_printf("404510755674075041024423598\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-348534895929485394582858326738598509248203842384 % 2340823481842304823490214");
	n = pop_num();
	ft_printf("-284457276307111591158348\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

parse_expr("3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333%1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	return (0);
}
