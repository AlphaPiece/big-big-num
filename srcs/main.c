/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:23:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 17:00:58 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bignum.h"

int		main(int argc, char **argv)
{
	t_bignum	bn1;
	t_bignum	bn2;
	t_numpart	*numpart;

	if (argc == 3)
	{
		convert(argv[1], ft_strlen(argv[1]), &bn1);
		convert(argv[2], ft_strlen(argv[2]), &bn1);
		add(bn1, bn2);
		for (numpart = bn1.head; numpart; numpart = numpart->next)
			ft_printf("%d\n", numpart->val);
		delete_all_parts(bn1.head);
		delete_all_parts(bn2.head);
	}
	return (0);
}
