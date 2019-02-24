/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 10:21:09 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 10:23:40 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int	main(int argc, char **argv)
{
	t_bignum	*n;
	int			x;
	t_bignum	*expo;

	if (argc == 3)
	{
		n = convert(argv[1]);
		x = ft_atoi(argv[2]);
		expo = exponent(n, x);
		print_num(expo);
		ft_printf("\n");
		
		delete_num(n);
		delete_num(expo);
	}
	return (0):
}
