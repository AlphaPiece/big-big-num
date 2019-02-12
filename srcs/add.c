/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:39:11 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/11 23:45:10 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Precondition:
**		1) n1, n2 contains only digit character
**		2) n1 >= n2
*/

char	**add(char *n1, char *n2)
{
	int			len1;
	int			len2;
	t_bignum	bn1;
	t_bignum	bn2;
	int			carry;
	int			i;
	int			j;
	int			bound;

	len1 = ft_strlen(n1);
	len2 = ft_strlen(n2);
	convert(n1, len1, bn1);
	convert(n2, len2, bn2);
	carry = 0;
	bound = PART_LEN * 10;
	i = bn1->partlen - 1;
	j = bn2->partlen - 1;
	while (i >= 0 || j >= 0 || carry != 0)
	{
		bn1->num[i] += ((j >= 0) ? bn2->num[j] : 0) + carry;
		if (bn1->num[i] > bound)
		{
			bn1->num[i] -= bound;
			carry++;
		}
		else
			carry = 0;
		i--;
		j--;
	}
	return (rconvert(bn1));
}			
