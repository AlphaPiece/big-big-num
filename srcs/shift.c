/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 23:41:21 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/18 21:00:46 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: shift >= 0
*/

void	left_shift(t_bignum *num, int shift)
{
	t_numpart	*part;
	int			mul10_p;
	int			mul10_q;
	int			front;
	int			back;
	int			carry;

	mul10_p = ft_pow(10, shift % PART_LEN);
	if (mul10_p > 0)
	{
		mul10_q = ft_pow(10, PART_LEN - shift % PART_LEN);
		carry = 0;
		part = num->tail;
		while (part || carry != 0)
		{
			front = part->val / mul10_q;
			back = part->val % mul10_q;
			part->val = back * mul10_p + carry;
			carry = front;
			part = part->prev;
			if (!part && carry != 0)
			{
				prepend_part(num, create_part(0));
				part = num->head;
			}
		}
	}
	while (shift - PART_LEN >= 0)
	{
		append_part(num, create_part(0));
		shift -= PART_LEN;
	}
}

void	right_shift(t_bignum *num, int shift)
{
	t_numpart	*part;
	int			mul10_p;
	int			mul10_q;
	int			front;
	int			back;
	int			borrow;

	while (shift - PART_LEN >= 0)
	{
		remove_back_part(num);
		shift -= PART_LEN;
	}
	mul10_p = ft_pow(10, shift);
	if (mul10_p > 0)
	{
		mul10_q = ft_pow(10, PART_LEN - shift);
		borrow = 0;
		part = num->head;
		while (part)
		{
			front = part->val / mul10_p;
			back = part->val % mul10_p;
			part->val = front + borrow;
			borrow = back * mul10_q;
			part = part->next;
		}
	}
	if (!num->head)
		append_part(num, create_part(0));
	while (num->head && num->head->next && num->head->val == 0)
		remove_front_part(num);
}
