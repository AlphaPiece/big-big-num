/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:15:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 21:53:31 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNC_H
# define BNC_H

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
void					prepend_part(t_bignum *num, t_numpart *part);
void					append_part(t_bignum *num, t_numpart *part);
void					delete_all_parts(t_bignum *num);

t_bignum				*create_num(void);

void					convert(char *s, int len, t_bignum *bn);

void					add(t_bignum *n1, t_bignum *n2);
void					subtract(t_bignum *n1, t_bignum *n2);

#endif
