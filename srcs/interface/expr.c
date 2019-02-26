/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:57:54 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/26 12:58:23 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		precedence(char op)
{
	if (op == '+' || op == '-')
		return (1);
	else if (op == '*' || op == '/' || op == '%')
		return (2);
	else if (op == '^' || op == '!')
		return (3);
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

int		 parse_subexpr(void)
{
	t_bignum	*num1;
	t_bignum	*num2;
	char		op;
	t_bignum	*num;

	if (!(op = pop_op()))
		return (ERROR);
	if (!(num2 = pop_num()))
		return (ERROR);
	if (op == '!')
	{
		if (!(num = apply_factorial(&num2)))
			return (ERROR);
	}
	else
	{
		if (!(num1 = pop_num()))
			return (ERROR);
		if (!(num = apply_op(op, &num1, &num2)))
			return (ERROR);
	}
	if (push_num(num) == OVERFLOW)
		return (OVERFLOW);
	return (NORM);
}

int		parse_expr(char *expr)
{
	int			i;
	char		last_elem;
	int			flag;
	t_bignum	*num;

	i = 0;
	last_elem = '(';
	while (expr[i])
	{
		while (ft_isspace(expr[i]))
			i++;
		if (!expr[i])
			break ;
		else if ((expr[i] == '-' || expr[i] == '+') &&
			(last_elem == '(' || IS_OP(last_elem)))
		{
			if ((flag = handle_sign(expr, &i, &last_elem)) != NORM)
				return (flag);
		}
		else if (ft_isdigit(expr[i]))
		{
			if ((flag = handle_digit(expr, &i, &last_elem, &num)) != NORM)
				return (flag);
		}
		else if (expr[i] == '(')
		{
			if (push_op(expr[i++]) == OVERFLOW)
				return (OVERFLOW);
			last_elem = '(';
		}
		else if (expr[i] == ')')
		{
			if ((flag = handle_bracket(&i, &last_elem)) != NORM)
				return (flag);
		}
		else if (expr[i] == '!')
		{
			if (last_elem != '0' && last_elem != ')')
				return (ERROR);
			if (push_op('!') == OVERFLOW)
				return (OVERFLOW);
			i++;
			last_elem = '!';
		}
		else if (IS_OP(expr[i]))
		{
			if ((flag = handle_operator(expr, &i, &last_elem)) != NORM)
				return (flag);
		}
		else
			i++;
	}
	while (!opstack_empty())
		if ((flag = parse_subexpr()) != NORM)
			return (flag);
	if (numstack_num_no() != 1)
		return (ERROR);
	return (NORM);
}
