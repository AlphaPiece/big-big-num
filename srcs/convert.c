/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:22:20 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 15:23:06 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bignum.h"

int         subconvert(char *s, int start, int len)
{
    int n;
    int i;

    i = start;
    n = 0;
    while (len--)
        n = n * 10 + s[i++] - '0';
    return (n);
}

void        convert(char *s, int len, t_bignum *bn)
{
    int         i;
    t_numpart   *new;

    i = len;
    j = bn->partlen - 1;
    while (i - PART_LEN >= 0)
    {
        new = create_numpart(subconvert(s, i - PART_LEN, PART_LEN));
        bn->numlist = prepend_numpart(bn->numlist, new);
        i -= PART_LEN;
    }
    if (i != 0)
    {
        new = create_numpart(subconvert(s, 0, i));
        bn->numlist = prepend_numpart(bn->numlist, new);
    }
}
