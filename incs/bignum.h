/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:15:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 17:01:30 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGNUM_H
# define BIGNUM_H

# include "libft.h"

# define PART_LEN	4

typedef struct			s_numpart
{
	int					val;
	struct s_numpart	*prev;
	struct s_numpart	*next;
}						t_numpart;

typedef struct			s_bignum
{
	t_numpart			*head;
	t_numpart			*tail;
	int					partlen;
}						t_bignum;

t_numpart				*create_part(int val);
t_numpart				*prepend_part(t_numpart *head, t_numpart *part);
void					delete_all_parts(t_numpart *head);

void					convert(char *s, int len, t_bignum *bn);

void					add(t_bignum *n1, t_bignum *n2);

#endif
