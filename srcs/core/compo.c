/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:53:40 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/20 16:55:38 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_compo		*create_compo(int x, int e10)
{
	t_compo	*compo;

	if (!(compo = (t_compo *)malloc(sizeof(t_compo))))
		return (NULL);
	compo->x = x;
	compo->e10 = e10;
	compo->next = NULL;
	return (compo);
}

void		append_compo(t_compo **compo_head, t_compo *new_compo)
{
	t_compo	*compo;

	if (!*compo_head)
		*compo_head = new_compo;
	else
	{
		compo = *compo_head;
		while (compo->next)
			compo = compo->next;
		compo->next = new_compo;
	}
}

t_compo		*get_compo_lst(t_bignum *num)
{
    t_numpart   *part;
    t_compo     *compo_head;
    t_compo     *compo;
    int         part_no;
    int         i;
    int         j;
    int         val;
    int         x;
    int         e10;
	int			mod;

    compo_head = NULL;
    part = num->head;
    part_no = get_part_no(num);
    i = -1;
    while (++i < part_no)
    {
        e10 = (part_no - i) * PART_LEN - 1;
        val = part->val;
		mod = ft_pow(10, PART_LEN - 1);
        j = -1;
        while (++j < PART_LEN)
        {
            x = val / mod;
			if (x != 0)
			{
				compo = create_compo(x, e10);
            	append_compo(&compo_head, compo);
			}
            e10--;
            val %= mod;
			mod /= 10;
        }
        part = part->next;
    }
    return (compo_head);
}

t_bignum	*revert_compo_lst(t_compo *compo_head)
{
	t_compo		*compo;
	t_bignum	*n1;
	t_bignum	*n2;

	if (!compo_head)
		return (NULL);
	compo = compo_head;
	if (!(n1 = init_num(compo->x)))
		return (NULL);
	left_shift(n1, compo->e10);
	compo = compo->next;
	while (compo)
	{
		if (!(n2 = init_num(compo->x)))
		{
			free(n1);
			return (NULL);
		}
		left_shift(n2, compo->e10);
		add(n1, n2);
		delete_num(&n2);
		compo = compo->next;
	}
	return (n1);
}	

void		delete_compo_lst(t_compo **compo_head)
{
	t_compo	*curr;
	t_compo	*next;

	if (!compo_head)
		return ;
	curr = *compo_head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*compo_head = NULL;
}
