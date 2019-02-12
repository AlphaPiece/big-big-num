/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:15:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/12 15:28:47 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGNUM_H
# define BIGNUM_H

# include "libft.h"

typedef struct			s_numpart
{
	int					val;
	struct s_numpart	*next;
}						t_numpart;

typedef struct			s_bignum
{
	t_numpart			*head;
	int					partlen;
}						t_bignum;

t_numpart				*create_numpart(int val);
t_numpart				*prepend_numpart(t_numpart *head, t_numpart *part);

void					convert(char *s, int len, t_bignum *bn);

#endif
