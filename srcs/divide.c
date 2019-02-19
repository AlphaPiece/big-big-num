/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:15:17 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 11:06:31 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

/*
** Precondition: n1 > n2
*/

t_bignum	*divide(t_bignum *n1, t_bignum *n2)
{
	t_compo		*compo_head;
	t_compo		*compo;
	t_bignum	*quotient;
	int			x;
	int			e10;
	int			len1;
	int			len2;
	int			len2_;

	len1 = get_digit_no(n1);
	len2 = get_digit_no(n2);
	len2_ = len1;
	left_shift(n2, len1 - len2);
	compo_head = NULL;
	while (true)
	{
		while (compare_num(n1, n2) < 0)
		{
			right_shift(n2, 1);
			len2_--;
		}
		if (len2_ < len2)
			break ;
		len1 = get_digit_no(n1);
		e10 = (len1 > len2_) ? len1 - len2 - 1 : len1 - len2;
		x = 0;
		while (compare_num(n1, n2) >= 0)
		{
			subtract(n1, n2);
			x++;
		}
		compo = create_compo(x, e10);
		append_compo(&compo_head, compo);
	}
	quotient = revert_compo_lst(compo_head);
	delete_compo_lst(&compo_head);
	return (quotient);
}
