/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:00:25 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 23:38:18 by Zexi Wang        ###   ########.fr       */
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

int     apply_op(char op, int val1, int val2)
{
    if (op == '+')
        return (val1 + val2);
    else if (op == '-')
        return (val1 - val2);
    else if (op == '*')
        return (val1 * val2);
    else if (op == '/')
        return (val1 / val2);
    else if (op == '%')
        return (val1 % val2);
	return (0);
}

void	parse_expr(char *expr)
{
	int		val;
	char	op;
	int		i;
	char	last_elem;

	i = 0;
	last_elem = '(';
	while (expr[i])
	{
		while (ft_isspace(expr[i]))
			i++;
		if (!expr[i])
			break ;
		if (expr[i] == '-' && (last_elem == '(' || IS_OP(last_elem)))
		{
			while (ft_isspace(expr[i]))
				i++;
			val = 0;
			while (ft_isdigit(expr[i]))
				val = val * 10 + expr[i++] - '0';
			push_val(-val);
			last_elem = '0';
		}
		else if (ft_isdigit(expr[i]))
		{
			val = 0;
			while (ft_isdigit(expr[i]))
				val = val * 10 + expr[i++] - '0';
			push_val(val);
			last_elem = '0';
		}
		else if (expr[i] == '(')
		{
			push_op(expr[i++]);
			last_elem = '(';
		}
		else if (expr[i] == ')')
		{
			while (!opstack_empty() && check_top_op() != '(')
			{
				op = pop_op();
				val = pop_val();
				push_val(apply_op(op, pop_val(), val));
			}
			pop_op();
			i++;
			last_elem = ')';
		}
		else if (IS_OP(expr[i]))
		{
			while (!opstack_empty() && 
					precedence(check_top_op()) >= precedence(expr[i]))
			{
				op = pop_op();
				val = pop_val();
				push_val(apply_op(op, pop_val(), val));
			}
			push_op(expr[i]);
			i++;
			last_elem = expr[i];
		}
		else
			i++;
	}
}

void	eval_expr(void)
{
	char	op;
	int		val;

	while (!opstack_empty())
	{
		op = pop_op();
		val = pop_val();
		push_val(apply_op(op, pop_val(), val));
	}
}
