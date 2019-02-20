/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:13:27 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 20:29:48 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

char	g_opstack[STACK_SPACE];
int		g_opindex = 0;

t_bool	opstack_empty(void)
{
	return (g_opindex == 0);
}

void	push_op(char op)
{
	if (g_opindex + 1 >= STACK_SPACE)
	{
		ft_dprintf(2, "bnc: stack full\n");
		exit(1);
	}
	g_opstack[g_opindex++] = op;
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
