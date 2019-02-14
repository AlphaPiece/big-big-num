/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:08:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 22:48:30 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		parse_number(char **expr)
{
	int	nbr;

	while (**expr == ' ')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		nbr = parse_sum(expr);
		if (** == ')')
			(*expr)++;
		return (nbr);
	}
	return (ft_atoi(expr));
}

int		parse_factors(char **expr)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = parse_number(expr);
	while (**expr)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '/' && op != '-' && op != '%')
			return (nbr);
		(*expr)++;
		nbr2 = parse_number(expr);
		if (op == '/')
			nbr /= nbr2;
		else if (op == '*')
			nbr *= nbr2;
		else
			nbr %= nbr2;
	}
	return (nbr);
}

int		parse_sum(char **expr)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = parse_factors(expr);
	while (**expr)
	{
		while (**expor == ' ')
			(*expr)++;
		op = **expr;
		if (op != '+' && op != '-')
			return (nbr);
		(*expr)++;
		nbr2 = parse_factors(expr);
		if (op == '+')
			nbr += nbr2;
		else
			nbr -= nbr2;
	}
	return (nbr);
}

int		eval_expr(char *expr)
{
	return (parse_sum(&expr));
}
