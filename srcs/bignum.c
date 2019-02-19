/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:27:14 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 10:29:04 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_bignum	*create_num(void)
{
	return (ft_memalloc(sizeof(t_bignum)));
}

t_bignum	*init_num(int val)
{
	t_bignum	*num;
	t_numpart	*part;
	
	if (!(num = create_num()))
		return (NULL);
	if (!(part = create_part(val)))
	{
		free(num);
		return (NULL);
	}
	num->head = part;
	num->tail = part;
	return (num);
}

t_bignum	*copy_num(t_bignum *num)
{
	t_bignum	*cpy;
	t_numpart	*part;
	t_numpart	*new_part;

	cpy = create_num();
	if (cpy)
	{
		part = num->head;
		while (part)
		{
			append_part(cpy, create_part(part->val));
			part = part->next;
		}
	}
	return (cpy);
}

void		print_num(t_bignum *num)
{
	t_numpart	*part;

	if (!num)
	{
		ft_printf("0\n");
		return ;
	}
	part = num->head;
	while (part && part->next && part->val == 0)
		part = part->next;
	while (part)
	{
		if (part == num->head)
			ft_printf("%d", part->val);
		else
			ft_printf("%04d", part->val);		
		part = part->next;
	}
	ft_printf("\n");
}

void        delete_num(t_bignum **num)
{
	t_numpart	*curr;
    t_numpart   *next;

	if (!num || !*num)
		return ;
	curr = (*num)->head;
    while (curr)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
	free(*num);
	*num = NULL;
}
