/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:23:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/15 00:11:02 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(int argc, char **argv)
{
	t_bignum	*bn1;
	t_bignum	*product;
	t_bignum	*bn2;
	t_numpart	*part;
	t_compo		*compo_head;
	t_compo		*compo;

	if (argc == 3)
	{
		bn1 = create_num();
		bn2 = create_num();
		convert(argv[1], ft_strlen(argv[1]), bn1);
		convert(argv[2], ft_strlen(argv[2]), bn2);
		
		product = multiply(bn1, bn2);
		print_num(product);

		delete_num(&bn1);
		delete_num(&product);
		delete_num(&bn2);
	}
	return (0);
}
