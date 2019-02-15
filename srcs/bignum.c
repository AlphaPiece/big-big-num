/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:27:14 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/14 22:53:41 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*create_num(void)
{
	return ((t_bignum *)ft_memalloc(sizeof(t_bignum)));
}

t_bignum	*copy_num(t_bignum *num)
{
	t_bignum	*cpy;
	t_numpart	*part;
	t_numpart	*new_part;

	cpy = create_num();
	if (cpy)
	{
		part = num->head;
		while (part)
		{
			append_part(cpy, create_part(part->val));
			part = part->next;
		}
	}
	return (cpy);
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

void		shift_num(t_bignum *num, int shift)
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

void		print_num(t_bignum *num)
{
	t_numpart	*part;

	part = num->head;
	while (part && part->val == 0)
		part = part->next;
	while (part)
	{
		if (part == num->head)
			ft_printf("%d", part->val);
		else
			ft_printf("%04d", part->val);		
		part = part->next;
	}
	ft_printf("\n");
}

void        delete_num(t_bignum **num)
{
	t_numpart	*curr;
    t_numpart   *next;

	curr = (*num)->head;
    next = curr->next;
    free(curr);
    while (next)
    {
        curr = next;
        next = curr->next;
        free(curr);
    }
	*num = NULL;
}
