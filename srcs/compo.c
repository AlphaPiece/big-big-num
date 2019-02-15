/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:53:40 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/14 23:52:17 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_compo	*create_compo(int x, int e10)
{
	t_compo	*compo;

	if (!(compo = (t_compo *)malloc(sizeof(t_compo))))
		return (NULL);
	compo->x = x;
	compo->e10 = e10;
	compo->next = NULL;
	return (compo);
}

void	append_compo(t_compo **compo_head, t_compo *new_compo)
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

t_compo *get_compo_lst(t_bignum *num)
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

void	delete_compo_lst(t_compo **compo_head)
{
	t_compo	*curr;
	t_compo	*next;

	curr = *compo_head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*compo_head = NULL;
}
