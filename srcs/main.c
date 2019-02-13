/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:23:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 21:52:19 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		main(int argc, char **argv)
{
	t_bignum	*bn1;
	t_bignum	*bn2;
	t_numpart	*numpart;

	if (argc == 3)
	{
		bn1 = create_num();
		bn2 = create_num();
		convert(argv[1], ft_strlen(argv[1]), bn1);
		convert(argv[2], ft_strlen(argv[2]), bn2);
		subtract(bn1, bn2);
		for (numpart = bn1->head; numpart; numpart = numpart->next)
			ft_printf("%04d", numpart->val);
		ft_printf("\n");
		delete_all_parts(bn1);
		delete_all_parts(bn2);
	}
	return (0);
}
