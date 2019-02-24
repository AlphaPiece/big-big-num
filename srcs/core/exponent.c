/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exponent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 09:57:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 10:19:00 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: x < EXPO_LIMIT
*/

t_bignum	*exponent(t_bignum *n, int x)
{
	t_bignum	*p[10];

	if (x == 1)
		return (n);
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
		p[1] = exponent(p[0], p[0]);
		p[2] = exponent(p[1], p[0]);
		p[3] = exponent(p[2], p[0]);
		p[4] = exponent(p[3], p[0]);
		delete_num(&p[0]);
		delete_num(&p[1]);
		delete_num(&p[2]);
		delete_num(&p[3]);
		return (p[4]);
	}
	else if (x % 7 == 0)
	{
		p[0] = exponent(n, x / 7);
		p[1] = exponent(p[0], p[0]);
		p[2] = exponent(p[1], p[0]);
		p[3] = exponent(p[2], p[0]);
		p[4] = exponent(p[3], p[0]);
		p[5] = exponent(p[4], p[0]);
		p[6] = exponent(p[5], p[0]);
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
		delete_num(p[0]);
		return (p[1]);
	}
}
