/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_divide_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 12:03:41 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("13332348023480 / 1000");
	n = pop_num();
	ft_printf("13332348023\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("123 / 11023");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-2345 / -90");
	n = pop_num();
	ft_printf("26\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-23 / -9090909");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-23450234 / 9971");
	n = pop_num();
	ft_printf("-2351\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-111 / 4243");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("9990483921 / -89");
	n = pop_num();
	ft_printf("-112252628\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("191 / -100000");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);	

	parse_expr("0 / -1");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-0 / 1");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("111111111111111111111 / 111111111111");
	n = pop_num();
	ft_printf("1000000000\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("21840192479147249493412349842431233241 / -2934");
	n = pop_num();
	ft_printf("-7443828384167433365171216715211735\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-923471934792102480123489024820 / -92349173824791738402184083048012834820781592374");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333 / 3");
	n = pop_num();
	ft_printf("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	return (0);
}
