/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:33:07 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/10 22:20:55 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bn_calc.h"

char	*add(char *n1, char *n2)
{
	char	*result;
	int		len0;
	int		len00;
	int		len1;
	int		len2;
	int		num1;
	int		num2;
	int		carry;
	int		remainder;
	int		sum;
	char	*tmp;

	len1 = ft_strlen(n1);
	len2 = ft_strlen(n2);
	len0 = MAX(len1, len2) + 1;
	len00 = len0;
	if (!(result = (char *)ft_memalloc(sizeof(char) * (len0 + 1))))
		return (NULL);
	result[len0--] = '\0';
	carry = 0;
	while (--len1 >= 0 || --len2 >= 0)
	{
		num1 = (len1 >= 0) ? n1[len1] - '0' : 0;
		num2 = (len2 >= 0) ? n2[len2] - '0' : 0;
		remainder = (num1 + num2) % 10;
		sum = remainder + carry;
		carry = (num1 + num2) / 10;
		if (sum >= 10)
		{
			carry += sum / 10;
			sum %= 10;
		}
		result[len0--] = sum + '0';
	}
	if (result[0] == 0)
	{
		tmp = result;
		result = ft_strsub(result, 1, len00 - 1);
		free(tmp);
	}
	return (result);
}

int		main()
{
	char	*n1 = "101";
	char	*n2 = "10";
	char	*result;

	result = add(n1, n2);
	ft_printf("%s\n", result);
	return (0);
}
