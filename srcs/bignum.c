/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:27:14 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/13 21:15:35 by Zexi Wang        ###   ########.fr       */
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
