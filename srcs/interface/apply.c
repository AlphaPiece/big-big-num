/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:29:50 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 23:38:16 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*apply_op(char op, t_bignum **n1, t_bignum **n2)
{
	t_bignum	*n;

    if (op == '+')
	{
		add(*n1, *n2);
		delete_num(n2);
        return (*n1);
	}
    else if (op == '-')
    {
		subtract(*n1, (n2);
		delete_num(n2);
		return (*n1);
	}
    else if (op == '*')
	{
		n = multiply(*n1, *n2);
		delete_num(n1);
		delete_num(n2);
        return (n);
	}
    else if (op == '/')
	{
		n = divide(*n1, *n2);
		delete_num(n1);
		delete_num(n2);
        return (n);
	}
    else if (op == '%')
    {
		modulo(*n1, *n2);
		delete_num(n2);
		return (*n1);
	}
    return (NULL);
}
