/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:27:14 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 12:25:20 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*create_num(void)
{
	return (ft_memalloc(sizeof(t_bignum)));
}

t_bignum	*init_num(int val)
{
	t_bignum	*num;
	t_numpart	*part;
	
	if (!(num = create_num()))
		return (NULL);
	if (!(part = create_part(val)))
	{
		free(num);
		return (NULL);
	}
	num->head = part;
	num->tail = part;
	if (val < 0)
		num->is_neg = true;
	else if (val == 0)
		num->is_zero = true;
	return (num);
}

t_bignum	*copy_num(t_bignum *num)
{
	t_bignum	*cpy;
	t_numpart	*part;

	if (!num)
		return (NULL);
	cpy = create_num();
	if (cpy)
	{
		part = num->head;
		while (part)
		{
			append_part(cpy, create_part(part->val));
			part = part->next;
		}
		cpy->is_neg = num->is_neg;
		cpy->is_zero = num->is_zero;
	}
	return (cpy);
}

void		remove_leading_zero(t_bignum *num)
{
	while (num->head && num->head->next && num->head->val == 0)
		remove_front_part(num);
}

void        delete_num(t_bignum **num)
{
	t_numpart	*curr;
    t_numpart   *next;

	if (!num || !*num)
		return ;
	curr = (*num)->head;
    while (curr)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
	free(*num);
	*num = NULL;
}
