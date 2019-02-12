/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_num_calc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:25:58 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/11 23:23:15 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_NUM_CALC_H
# define BIG_NUM_CALC_H

# include "libft.h"

# define PART_LEN	9

typedef struct	s_analysis
{
	char		*max;
	char		*min;
	t_bool		is_negative;
}				t_analysis;
	
t_bool			check(char *n);
t_analysis		analyze(char *n1, char *n2);

typdef struct	s_bignum
{
	int			*num;
	int			partlen;
}				t_bignum;

int				*convert(char *s, int len, int *partlen);

char			*add(char *n1, char *n2);
char			*subtract(char *n1, char *n2);

#endif
