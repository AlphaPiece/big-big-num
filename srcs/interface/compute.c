/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:27:46 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 10:11:44 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bool	is_valid_char(char c)
{
	return (ft_isspace(c) || c == 37 || (c >= 40 && c <= 43) || c == 45 ||
			(c >= 47 && c <= 57));
}

void	compute(void)
{
	char		*line;
	int			i;
	t_bool		is_invalid;
	t_bignum	*num;

	while (ft_nextline(1, &line) > 0 && !ft_strequ(line, "quit"))
	{
		i = -1;
		is_invalid = false;
//		ft_printf("a\n");
		while (line[++i])
			if (!is_valid_char(line[i]))
			{
				is_invalid = true;
				break ;
			}
//		ft_printf("b\n");
		if (is_invalid || !parse_expr(line))
		{
//			ft_printf("c\n");
//			ft_printf("is %s invalid\n", is_invalid ? "" : "not");
			ft_printf("bc: invalid input\n");
			clear_numstack();
			clear_opstack();
		}
		else
		{
//			ft_printf("d\n");
			num = pop_num();
			print_num(num);
			delete_num(&num);
		}
//		ft_printf("e\n");
		free(line);
	}
	if (ft_strequ(line, "quit"))
		free(line);
}
