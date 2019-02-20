/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:27:46 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 21:18:12 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		compute(char *expr)
{
	parse_expr(expr);
	eval_expr();
	return (pop_val());
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_printf("result: %d\n", compute(argv[1]));
	}
	return (0);
}
