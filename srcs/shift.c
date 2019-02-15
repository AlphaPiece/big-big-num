/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 23:41:21 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/15 00:10:25 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: shift >= 0
*/

void	left_shift(t_bignum *num, int shift)
{
	t_numpart	*part;
	int			small_shift;
	int			bound;
	int			carry;

	small_shift = ft_pow(10, shift % PART_LEN);
	bound = ft_pow(10, PART_LEN);
	carry = 0;
	part = num->tail;
	if (small_shift > 0)
		while (part || carry != 0)
		{
			part->val = part->val * small_shift + carry;
			if (part->val > PART_LEN)
			{
				carry = part->val / bound;
				part->val %= bound;
			}
			else
				carry = 0;
			if (part)
				part = part->prev;
			if (!part && carry != 0)
			{
				prepend_part(num, create_part(0));
				part = num->head;
			}
		}
	while (shift - PART_LEN >= 0)
	{
		append_part(num, create_part(0));
		shift -= PART_LEN;
	}
}
