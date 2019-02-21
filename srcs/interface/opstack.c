/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:13:27 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 10:13:20 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

char	g_opstack[STACK_SPACE];
int		g_opindex = 0;

t_bool	opstack_empty(void)
{
	return (g_opindex == 0);
}

int		push_op(char op)
{
	if (g_opindex + 1 >= STACK_SPACE)
		return (ERROR);
	g_opstack[g_opindex++] = op;
	return (NORM);
}

char	pop_op(void)
{
	if (g_opindex - 1 < 0)
		return ('\0');
	return (g_opstack[--g_opindex]);
}

char	check_top_op(void)
{
	if (g_opindex - 1 < 0)
		return ('\0');
	return (g_opstack[g_opindex - 1]);
}

void	print_opstack(void)
{
	for (int i = 0; i < g_opindex; i++)
		ft_printf("%c ", g_opstack[i]);
	ft_printf("\n");
}

void	clear_opstack(void)
{
	g_opindex = 0;
}
