/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:22:20 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 12:18:46 by Zexi Wang        ###   ########.fr       */
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
	t_bignum	*num;
    t_numpart   *part;

	if (!(num = create_num()))
		return (NULL);
    while (len - PART_LEN >= 0)
    {
        part = create_part(subconvert(s, len - PART_LEN, PART_LEN));
        prepend_part(num, part);
        len -= PART_LEN;
    }
    if (len != 0)
    {
        part = create_part(subconvert(s, 0, len));
        prepend_part(num, part);
    }
	remove_leading_zero(num);
	if (num->head == num->tail && num->head->val == 0)
		num->is_zero = true;
	return (num);
}
