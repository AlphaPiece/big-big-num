/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:27:14 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/14 00:37:40 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*create_num(void)
{
	return ((t_bignum *)ft_memalloc(sizeof(t_bignum)));
}

int			get_part_no(t_bignum *num)
{
	t_numpart	*part;
	int			part_no;

	part = num->head;
	part_no = 0;
	while (part)
	{
		part = part->next;
		part_no++;
	}
	return (part_no);
}

void		shift_all_parts(t_bignum *num, int shift)
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
	while (shift - PART_LEN > 0)
	{
		append_part(num, create_part(0));
		shift -= PART_LEN;
	}
}	

void        delete_all_parts(t_bignum *num)
{
	t_numpart	*curr;
    t_numpart   *next;

	curr = num->head;
    next = curr->next;
    free(curr);
    while (next)
    {
        curr = next;
        next = curr->next;
        free(curr);
    }
}
