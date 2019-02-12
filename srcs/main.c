/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:23:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 15:26:44 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bignum.h"

int		main(int argc, char **argv)
{
	t_bignum	bn;
	t_numpart	*numpart;

	if (argc == 2)
	{
		convert(argv[1], ft_strlen(argv[1]), bn);
		for (numpart = bn->head; numpart; numpart = numpart->next)
			ft_printf("%d\n", numpart->val);
	}
	return (0);
}
