/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:29:50 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 12:40:17 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*apply_add_multiply(char op, t_bignum **n1, t_bignum **n2)
{
	t_bignum	*n;

	if (compare_num(*n1, *n2) < 0)
		ft_memswap(n1, n2, sizeof(*n1));
    if (op == '+')
	{
		if ((*n2)->is_zero)
		{
			delete_num(n2);
			return (*n1);
		}
		if (same_sign(*n1, *n2))
			add(*n1, *n2);
		else
			subtract(*n1, *n2);
		delete_num(n2);
		return (*n1);
	}
    else
	{
		if ((*n1)->is_zero || (*n2)->is_zero)
			n = init_num(0);
		else
		{
			n = multiply(*n1, *n2);
			if (!same_sign(*n1, *n2))
				n->is_neg = true;
			else
				n->is_neg = false;
		}
		delete_num(n1);
		delete_num(n2);
        return (n);
	}
}

t_bignum	*apply_subtract(t_bignum **n1, t_bignum **n2)
{
	t_bool		is_neg;

	if ((*n2)->is_zero)
	{
		delete_num(n2);
		return (*n1);
	}
	else if ((*n1)->is_zero)
	{
		(*n2)->is_neg = !(*n2)->is_neg;
		delete_num(n1);
		return (*n2);
	}
	if (!same_sign(*n1, *n2))
	{
		is_neg = false;
		if ((*n1)->is_neg)
			is_neg = true;
		if (compare_num(*n1, *n2) < 0)
			ft_memswap(n1, n2, sizeof(*n1));
		add(*n1, *n2);
		(*n1)->is_neg = is_neg;
		delete_num(n2);
		return (*n1);
	}
	else
	{
		if (compare_num(*n1, *n2) < 0)
		{
			subtract(*n2, *n1);
			(*n2)->is_neg = !(*n2)->is_neg;
			delete_num(n1);
			return (*n2);
		}
		else
		{
			subtract(*n1, *n2);
			delete_num(n2);
			return (*n1);
		}
	}
}	

t_bignum	*apply_divide_mudolo(char op, t_bignum **n1, t_bignum **n2)
{
	t_bignum	*n;

	if ((*n2)->is_zero)
	{
		delete_num(n1);
		delete_num(n2);
		return (NULL);
	}
	else if ((*n1)->is_zero)
	{
		delete_num(n2);
		return (*n1);
	}
	if (op == '/')
	{
		n = divide(*n1, *n2);
		if (!same_sign(*n1, *n2))
			n->is_neg = true;
		delete_num(n1);
		delete_num(n2);
        return (n);
	}
    else
    {
		if (compare_num(*n1, *n2) < 0)
		{
			delete_num(n2);
			return (*n1);
		}
		else
		{
			modulo(*n1, *n2);
			delete_num(n2);
			return (*n1);
		}
	}
}

t_bignum	*apply_exponent(t_bignum **n1, t_bignum **n2)
{
	t_bignum	*n;

	if (get_digit_no(*n2) > EXPO_LIMIT || (*n2)->is_neg)
	{
		delete_num(n1);
		delete_num(n2);
		return (NULL);
	}
	else
	{
		n = exponent(*n1, (*n2)->head->val);
		delete_num(n1);
		delete_num(n2);
		return (n);
	}
}	

t_bignum	*apply_factorial(t_bignum **n)
{
	t_bignum	*m;

	if (get_digit_no(*n) > FACT_LIMIT || (*n)->is_neg)
	{
		delete_num(n);
		return (NULL);
	}
	else
	{
		m = factorial((*n)->head->val);
		delete_num(n);
		return (m);
	}
}

t_bignum	*apply_op(char op, t_bignum **n1, t_bignum **n2)
{
	t_bignum	*n;

	if (op == '+' || op == '*')
		n = apply_add_multiply(op, n1, n2);
	else if (op == '-')
		n = apply_subtract(n1, n2);
	else if (op == '/' || op == '%')
		n = apply_divide_mudolo(op, n1, n2);
	else
		n = apply_exponent(n1, n2);
	if (n && n->head == n->tail && n->head->val == 0)
		n->is_zero = true;
	return (n);
}
