/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_subtract_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 11:51:10 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("1000 - 21");
	n = pop_num();
	ft_printf("979\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("123 - 456");
	n = pop_num();
	ft_printf("-333\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-2345 - -90");
	n = pop_num();
	ft_printf("-2255\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-111 - -333");
	n = pop_num();
	ft_printf("222\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-999 - 89");
	n = pop_num();
	ft_printf("-1088\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-77 - 7000000000000");
	n = pop_num();
	ft_printf("-7000000000077\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("11234 - - 234");
	n = pop_num();
	ft_printf("11468\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("11 - - 234123");
	n = pop_num();
	ft_printf("234134\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-11111111111111 - 11111111111111");
	n = pop_num();
	ft_printf("-22222222222222\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-111111111111 -   - 11111111111111");
	n = pop_num();
	ft_printf("11000000000000\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-       1234567890  \n  - -0987654321");
	n = pop_num();
	ft_printf("-246913569\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-000000000000000 - 0000000");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	return (0);
}
