/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 23:53:54 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/11 00:30:26 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_num_calc.h"

/*
** Precondition: n1 > n2
*/

char	*subtract(char *n1, char *n2)
{
	char	*result;
	int		i;
	int		j;
	int		k;
	int		num1;
	int		num2;
	int		borrow;
	int		difference;
	
	j = ft_strlen(n1) - 1;
	k = ft_strlen(n2) - 1;
	i = j + 1;
	if (!(result = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	borrow = 0;
	while (j >= 0 || k >= 0 || borrow > 0)
	{
		num1 = n1[j] - '0';
		num2 = (k >= 0) ? n2[k] - '0' : 0;
		difference = num1 - num2 - borrow;
		if (difference < 0)
		{
			difference += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		result[i--] = difference + '0';
		j--;
		k--;
	}
	return (result);
}

