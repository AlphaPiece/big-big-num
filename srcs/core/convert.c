/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:22:20 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/20 16:00:36 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int			subconvert(char *s, int start, int len)
{
    int n;
    int i;

    i = start;
    n = 0;
    while (len--)
        n = n * 10 + s[i++] - '0';
    return (n);
}

t_bignum	*convert(char *s, int len)
{
    int         i;
	t_bignum	*num;
    t_numpart   *part;

	if (!(num = create_num()))
		return (NULL);
    i = len;
    while (i - PART_LEN >= 0)
    {
        part = create_part(subconvert(s, i - PART_LEN, PART_LEN));
        prepend_part(num, part);
        i -= PART_LEN;
    }
    if (i != 0)
    {
        part = create_part(subconvert(s, 0, i));
        prepend_part(num, part);
    }
	remove_leading_zero(num);
	if (num->head == num->tail && num->head->val == 0)
		num->is_zero = true;
	return (num);
}
