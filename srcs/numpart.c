/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:22:02 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 15:28:49 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bignum.h"

t_numpart   *create_numpart(int n)
{
    t_numpart   *new;

    if (!(new = (t_numpart *)malloc(sizeof(t_numpart))))
        return (NULL);
    new->val = n;
    new->next = NULL;
}

t_numpart   *prepend_numpart(t_numpart *head, t_numpart *part)
{
    if (*head)
        new->next = head;
    return (new);
}
