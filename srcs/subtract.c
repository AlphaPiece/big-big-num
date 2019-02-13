/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:44:46 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 21:51:57 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: n1 >= n2
*/

void	subtract(t_bignum *n1, t_bignum *n2)
{
	int			borrow;
	int			bound;
	t_numpart	*p;
	t_numpart	*q;

	borrow = 0;
	bound = ft_pow(10, PART_LEN);
	p = n1->tail;
	q = n2->tail;
	while (p || q || borrow != 0)
	{
		p->val -= (((q) ? q->val : 0) + borrow);
		if (p->val < 0)
		{
			p->val += bound;
			borrow = 1;
		}
		else
			borrow = 0;
		if (q)
			q = q->prev;
		if (p)
			p = p->prev;
	}
}
