/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:39:04 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/14 22:47:30 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: n1 > n2
*/

t_bignum	*multiply(t_bignum *n1, t_bignum *n2)
{
	t_compo		*compo_head;
	t_compo		*compo;
	t_bignum	*product;
	t_bignum	*cpy1;
	t_bignum	*cpy2;
	t_bool		first_round;
	int			i;

	compo_head = get_compo_lst(n2);
	if (!compo_head)
	{
		product = create_num();
		prepend_part(product, create_part(0));
		return (product);
	}
	compo = compo_head;
	first_round = true;
	while (compo)
	{
		cpy1 = copy_num(n1);
		shift_num(cpy1, compo->e10);
		cpy2 = copy_num(cpy1);
		i = 0;
		while (++i < compo->x)
			add(cpy1, cpy2);
		if (first_round)
		{
			product = cpy1;
			delete_num(&cpy2);
			first_round = false;
		}
		else
		{
			add(product, cpy1);
			delete_num(&cpy1);
			delete_num(&cpy2);
		}
		compo = compo->next;
	}
	return (product);
}
