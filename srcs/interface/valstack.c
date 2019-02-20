/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:54:57 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 21:03:00 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		g_valstack[STACK_SPACE];
int		g_valindex = 0;

t_bool	valstack_empty(void)
{
	return (g_valindex == 0);
}

void	push_val(int val)
{
	if (g_valindex + 1 >= STACK_SPACE)
	{
		ft_dprintf(2, "bnc: stack full\n");
		exit(1);
	}
	g_valstack[g_valindex++] = val;
}

int		pop_val(void)
{
	if (g_valindex - 1 < 0)
		return (0);
	return (g_valstack[--g_valindex]);
}

void	print_valstack(void)
{
	for (int i = 0; i < g_valindex; i++)
		ft_printf("%d ", g_valstack[i]);
	ft_printf("\n");
}
