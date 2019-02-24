/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exponent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 09:57:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 14:02:52 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: 0 <= x <= EXPO_LIMIT
*/

t_bignum	*exponent(t_bignum *n, int x)
{
	t_bignum	*p[7];

	if (x <= 0)
		return (init_num(1));
	else if (n->is_zero || x == 1)
		return (copy_num(n));
	else if (n->is_neg)
	{
		p[0] = copy_num(n);
		p[0]->is_neg = false;
		p[1] = exponent(p[0], x);
		delete_num(&p[0]);
		if (x % 2 == 0)
			p[1]->is_neg = false;
		else
			p[1]->is_neg = true;
		return (p[1]);
	}
	else if (x % 2 == 0)
	{
		p[0] = exponent(n, x / 2);
		p[1] = multiply(p[0], p[0]);
		delete_num(&p[0]);
		return (p[1]);
	}
	else if (x % 3 == 0)
	{
		p[0] = exponent(n, x / 3);
		p[1] = multiply(p[0], p[0]);
		p[2] = multiply(p[1], p[0]);
		delete_num(&p[0]);
		delete_num(&p[1]);
		return (p[2]);
	}
	else if (x % 5 == 0)
	{
		p[0] = exponent(n, x / 5);
		p[1] = multiply(p[0], p[0]);
		p[2] = multiply(p[1], p[0]);
		p[3] = multiply(p[2], p[0]);
		p[4] = multiply(p[3], p[0]);
		delete_num(&p[0]);
		delete_num(&p[1]);
		delete_num(&p[2]);
		delete_num(&p[3]);
		return (p[4]);
	}
	else if (x % 7 == 0)
	{
		p[0] = exponent(n, x / 7);
		p[1] = multiply(p[0], p[0]);
		p[2] = multiply(p[1], p[0]);
		p[3] = multiply(p[2], p[0]);
		p[4] = multiply(p[3], p[0]);
		p[5] = multiply(p[4], p[0]);
		p[6] = multiply(p[5], p[0]);
		delete_num(&p[0]);
		delete_num(&p[1]);
		delete_num(&p[2]);
		delete_num(&p[3]);
		delete_num(&p[4]);
		delete_num(&p[5]);
		return (p[6]);
	}
	else
	{
		p[0] = exponent(n, x - 1);
		p[1] = multiply(p[0], n);
		delete_num(&p[0]);
		return (p[1]);
	}
}
