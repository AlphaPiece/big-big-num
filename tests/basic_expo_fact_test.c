/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_expo_fact_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 14:15:26 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	t_bignum	*n;
	
	parse_expr("10 ^ 100");
	n = pop_num();
	ft_printf("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("0^1");
	n = pop_num();
	ft_printf("0\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("32^0");
	n = pop_num();
	ft_printf("1\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-2^6");
	n = pop_num();
	ft_printf("64\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-(2^6)");
	n = pop_num();
	ft_printf("-64\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-2^5");
	n = pop_num();
	ft_printf("-32\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-(2^5)");
	n = pop_num();
	ft_printf("-32\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-1     ^(23 - 23)");
	n = pop_num();
	ft_printf("1\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);	

	parse_expr("0!");
	n = pop_num();
	ft_printf("1\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("1!");
	n = pop_num();
	ft_printf("1\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("100!");
	n = pop_num();
	ft_printf("93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("5 * 50!");
	n = pop_num();
	ft_printf("152070466008566890218063040830323844221888207844802560000000000000\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	parse_expr("-(25 * 2)!");
	n = pop_num();
	ft_printf("-30414093201713378043612608166064768844377641568960512000000000000\n");
	print_num(n); ft_printf("\n");
	delete_num(&n);

	return (0);
}
