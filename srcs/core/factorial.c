/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorial.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:11:57 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 11:26:41 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: 0 <= x <= FACT_LIMIT
*/

t_bignum	*factorial(int x)
{
	t_bignum	*tab[10000];
	int			i;

	tab[0] = init_num(1);
	i = 0;
	while (++i <= x)
	{
		tab[i] = multiply(init_num(i), tab[i - 1]);
		delete_num(&tab[i - 1]);
	}
	return (tab[x]);
}
