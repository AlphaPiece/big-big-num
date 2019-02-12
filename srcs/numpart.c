/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:22:02 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 16:43:37 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bignum.h"

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

t_numpart   *prepend_part(t_numpart *head, t_numpart *part)
{
    if (head)
	{
        part->next = head;
		head->prev = part;
	}
    return (part);
}

t_numpart	*append_part(t_numpart *tail, t_numpart *part)
{
	if (tail)
	{
		tail->next = part;
		part->prev = tail;
	}
	return (part);
}

void		delete_all_parts(t_numpart *head)
{
	t_numpart	*next;

	next = head->next;
	free(head);
	while (next)
	{
		head = next;
		next = head->next;
		free(head);
	}
}
