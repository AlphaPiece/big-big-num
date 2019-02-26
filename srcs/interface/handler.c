/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:57:34 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/26 13:05:09 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int	 handle_digit(char *expr, int *i, char *last_elem, t_bignum **num)
{
	if ((*num = parse_num(expr, i)))
	{
		if (push_num(*num) == OVERFLOW)
			return (OVERFLOW);
	}
	else
		return (ERROR);
	*last_elem = '0';
	return (NORM);
}

int	 handle_sign(char *expr, int *i, char *last_elem)
{
	t_bignum	*num;
	int		 	flag;

	*last_elem = expr[*i];
	while (ft_isspace(expr[++*i]))
		;
	if (expr[*i] == '(')
	{
		num = init_num(0);
		if (push_num(num) == OVERFLOW || push_op('-') == OVERFLOW)
			return (OVERFLOW);
		*last_elem = '-';
		return (NORM);
	}
	else
	{
		if ((flag = handle_digit(expr, i, last_elem, &num)) == NORM)
		{
			num->is_neg = true;
			return (NORM);
		}
		else
			return (flag);
	}
}

int	 handle_bracket(int *i, char *last_elem)
{
	int flag;

	while (!opstack_empty() && check_top_op() != '(')
		if ((flag = parse_subexpr()) != NORM)
			return (flag);
	if (!pop_op())
		return (ERROR);
	++*i;
	*last_elem = ')';
	return (NORM);
}

int	 handle_operator(char *expr, int *i, char *last_elem)
{
	int	flag;

	while (!opstack_empty() &&
		   precedence(check_top_op()) >= precedence(expr[*i]))
		if ((flag = parse_subexpr()) != NORM)
			return (flag);
	if (push_op(expr[*i]) == OVERFLOW)
		return (OVERFLOW);
	*last_elem = expr[*i];
	++*i;
	return (NORM);
}
