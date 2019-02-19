/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:21:35 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/19 11:27:21 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

void	modulo(t_bignum *n1, t_bignum *n2)
{
	int	len1;
	int	len2;
	int	len2_;

	len1 = get_digit_no(n1);
	len2 = get_digit_no(n2);
	len2_ = len1;
	left_shift(n2, len1 - len2);
	while (true)
	{
		while (compare_num(n1, n2) < 0)
		{
			right_shift(n2, 1);
			len2_--;
		}
		if (len2_ < len2)
			break ;
		while (compare_num(n1, n2) >= 0)
			subtract(n1, n2);
	}
}
