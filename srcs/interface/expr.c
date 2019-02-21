/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:00:25 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 11:41:43 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		precedence(char op)
{
	if (op == '+' || op == '-')
		return (1);
	else if (op == '*' || op == '/' || op == '%')
		return (2);
	return (0);
}

t_bignum	*parse_num(char *expr, int *i)
{
	int			j;

	j = *i;
	while (ft_isdigit(expr[*i]))
		++*i;
	if (*i - j == 0)
		return (NULL);
	return (convert(&expr[j], *i - j));
}	

int			parse_subexpr(void)
{
	t_bignum	*n1;
	t_bignum	*n2;
	char		op;
	t_bignum	*n;

	if (!(n2 = pop_num()))
		return (ERROR);
	if (!(n1 = pop_num()))
		return (ERROR);
	if (!(op = pop_op()))
		return (ERROR);
	if (!(n = apply_op(op, &n1, &n2)))
		return (ERROR);
	push_num(n);
	return (NORM);
}

int			parse_expr(char *expr)
{
	t_bignum	*num;
	int			i;
	char		last_elem;

	i = 0;
	last_elem = '(';
	while (expr[i])
	{
		while (ft_isspace(expr[i]))
			i++;
		if (!expr[i])
			break ;
		if ((expr[i] == '-' || expr[i] == '+') &&
			(last_elem == '(' || IS_OP(last_elem)))
		{
			last_elem = expr[i];
			while (ft_isspace(expr[++i]))
				;
			if ((num = parse_num(expr, &i)))
			{
				if (last_elem == '-')
					num->is_neg = true;
				if (!push_num(num))
					return (ERROR);
			}
			last_elem = '0';
		}	
		else if (ft_isdigit(expr[i]))
		{
			if ((num = parse_num(expr, &i)))
				if (!push_num(num))
					return (ERROR);
			last_elem = '0';
		}
		else if (expr[i] == '(')
		{
			if (!push_op(expr[i++]))
				return (ERROR);
			last_elem = '(';
		}
		else if (expr[i] == ')')
		{
			while (!opstack_empty() && check_top_op() != '(')
				if (!parse_subexpr())
					return (ERROR);
			if (!pop_op())
				return (ERROR);
			i++;
			last_elem = ')';
		}
		else if (IS_OP(expr[i]))
		{
			while (!opstack_empty() && 
					precedence(check_top_op()) >= precedence(expr[i]))
				if (!parse_subexpr())
					return (ERROR);
			if (!push_op(expr[i]))
				return (ERROR);
			last_elem = expr[i++];
		}
		else
			i++;
	}
	while (!opstack_empty())
		if (!parse_subexpr())
			return (ERROR);
	if (numstack_num_no() != 1)
		return (ERROR);
	return (NORM);
}
