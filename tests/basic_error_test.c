/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_error_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:35:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 14:51:40 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(void)
{
	int	flag;
	
	flag = parse_expr("50 - (40");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("20 - 99 / (96 - 30 * (57 - 76) - --43 % 20) - 17");
	ft_printf("invalid\n");
    ft_printf("%s\n", (flag) ? "no error" : "error");	

	flag = parse_expr("++++-0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("-2234 ----");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("20+19*(13+59/(6+4)-97%)-76");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("123 + 234 / 2a");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("1 / -0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("-1 / +0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("-199 / 0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("-1 % +0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("1 % -0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("-1 % 1 / +0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("0 % 1 % 0");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("-1!");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("10000!");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	flag = parse_expr("12^1000000000");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");flag = parse_expr("10000!");

	flag = parse_expr(" 12!!");
	ft_printf("invalid\n");
	ft_printf("%s\n", (flag) ? "no error" : "error");

	return (0);
}
