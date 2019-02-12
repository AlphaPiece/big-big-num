/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:41:42 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/11 23:46:21 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_num_calc.h"

int		subconvert(char *s, int start, int len)
{
	int	n;
	int	i;

	i = start;
	n = 0;
	while (len--)
		n = n * 10 + s[i++] - '0';
	return (n);
}

void	convert(char *s, int len, t_bignum *bn)
{
	int	i;
	int	j;

	bn->partlen = len / PART_LEN + 1;
	if (!(bn->num = (int *)ft_memalloc(sizeof(int) * bn->partlen)))
		return (NULL);
	i = len;
	j = bn->partlen - 1;
	while (i - PART_LEN >= 0)
	{
		bn->num[j] = subconvert(s, i - PART_LEN, PART_LEN);
		i -= PART_LEN;
		j--;
	}
	if (i != 0)
		bn->num[j] = subconvert(s, 0, i);
}

char	**rconvert(t_bignum *bn)
{
	char	**num;
	int		i;
	
	if (!(num = (char **)malloc(sizeof(char *) * (bn->partlen + 1))))
		return (NULL);
	i = -1;
	while (++i < bn->partlen)
		num[i] = ft_itoa(bn->num[i]);
	num[i] = NULL;
	return (num);
}
