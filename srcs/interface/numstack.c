/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:54:57 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/24 14:08:01 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*g_numstack[STACK_SPACE];
int			g_numindex = 0;

t_bool		numstack_empty(void)
{
	return (g_numindex == 0);
}

int			push_num(t_bignum *num)
{
	if (g_numindex + 1 >= STACK_SPACE)
		return (ERROR);
	g_numstack[g_numindex++] = num;
	return (NORM);
}

t_bignum	*pop_num(void)
{
	if (g_numindex - 1 < 0)
		return (NULL);
	return (g_numstack[--g_numindex]);
}

void		print_numstack(void)
{
	for (int i = 0; i < g_numindex; i++)
	{
		print_num(g_numstack[i]);
		ft_printf(" ");
	}
	ft_printf("\n");
}

int			numstack_num_no(void)
{
	return (g_numindex);
}

void		clear_numstack(void)
{
	while (g_numindex - 1 >= 0)
		delete_num(&g_numstack[--g_numindex]);
}
