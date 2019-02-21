/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:02:41 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 09:57:18 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

int		get_part_no(t_bignum *num)
{
	t_numpart	*part;
	int			part_no;

	part = num->head;
	part_no = 0;
	while (part)
	{
		part = part->next;
		part_no++;
	}
	return (part_no);
}

int		get_digit_no(t_bignum *num)
{
	return (get_part_no(num) * PART_LEN + ft_numlen(num->head->val));
}

int		compare_num(t_bignum *n1, t_bignum *n2)
{
	int			part_no_1;
	int			part_no_2;
	t_numpart	*part1;
	t_numpart	*part2;

	part_no_1 = get_part_no(n1);
	part_no_2 = get_part_no(n2);
	if (part_no_1 > part_no_2)
		return (1);
	else if (part_no_1 < part_no_2)
		return (-1);
	part1 = n1->head;
	part2 = n2->head;
	while (part1)
	{
		if (part1->val > part2->val)
			return (1);
		else if (part1->val < part2->val)
			return (-1);
		part1 = part1->next;
		part2 = part2->next;
	}
	return (0);
}

t_bool	same_sign(t_bignum *n1, t_bignum *n2)
{
	return ((n1->is_neg && n2->is_neg) || !(n1->is_neg || n2->is_neg));
}

void	print_num(t_bignum *num)
{
    t_numpart   *part;

    if (!num || num == (void *)ERROR)
        return ;
    if (num->is_neg && !num->is_zero)
        ft_printf("-");
    part = num->head;
    while (part && part->next && part->val == 0)
        part = part->next;
    while (part)
    {
        if (part == num->head)
            ft_printf("%d", part->val);
        else
            ft_printf("%0*d", PART_LEN, part->val);
        part = part->next;
    }
    ft_printf("\n");
}
