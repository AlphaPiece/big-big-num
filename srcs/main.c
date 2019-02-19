/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:23:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 10:56:15 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(int argc, char **argv)
{
	t_bignum	*bn1;
	t_bignum	*quotient;
	t_bignum	*bn2;
	t_numpart	*part;
	t_compo		*compo_head;
	t_compo		*compo;
	t_bignum	*bn3;

	if (argc == 3)
	{
		bn1 = convert(argv[1], ft_strlen(argv[1]));
		bn2 = convert(argv[2], ft_strlen(argv[2]));
		
		quotient = divide(bn1, bn2);
		print_num(quotient);

		delete_num(&bn1);
		delete_num(&bn2);
		delete_num(&quotient);
	}
	return (0);
}
