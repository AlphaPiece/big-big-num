/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:22:02 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/18 20:08:17 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bnc.h"

t_numpart   *create_part(int n)
{
    t_numpart   *part;

    if (!(part = (t_numpart *)malloc(sizeof(t_numpart))))
        return (NULL);
    part->val = n;
	part->prev = NULL;
    part->next = NULL;
	return (part); 
}

void		prepend_part(t_bignum *num, t_numpart *part)
{
    t_numpart	*tmp;
	
	if (!num->head)
	{
		num->head = part;
		num->tail = part;
	}
	else
	{
		tmp = num->head;
		num->head = part;
		part->next = tmp;
		tmp->prev = part;
	}
}

void		append_part(t_bignum *num, t_numpart *part)
{
	t_numpart	*tmp;

	if (!num->tail)
	{
		num->tail = part;
		num->head = part;
	}
	else
	{
		tmp = num->tail;
		num->tail = part;
		part->prev = tmp;
		tmp->next = part;
	}
}

void		remove_front_part(t_bignum *num)
{
	t_numpart	*end;

	if (num->head)
	{
		end = num->head->next;
		free(num->head);
		if (end)
		{
			end->prev = NULL;
			num->head = end;
		}
		else
		{
			num->head = NULL;
			num->tail = NULL;
		}
	}
}

void		remove_back_part(t_bignum *num)
{
	t_numpart	*end;

	if (num->tail)
	{
		end = num->tail->prev;
		free(num->tail);
		if (end)
		{
			end->next = NULL;
			num->tail = end;
		}
		else
		{
			num->head = NULL;
			num->tail = NULL;
		}
	}
}
