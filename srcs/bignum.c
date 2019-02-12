/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:27:14 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 18:18:11 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*create_num(void)
{
	return ((t_bignum *)ft_memalloc(sizeof(t_bignum)));
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
