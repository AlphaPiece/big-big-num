/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:10:34 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/01/22 22:43:56 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*calc_layer(char *m1, char *m2, int pow_ten, int base);

char	*comb_layer(char *layer_sum, char *layer);

char	*trim_zero(char *layer_sum);

char	*ft_multiply(char *a, char *b, int base)
{
	int		len0;
	int		len1;
	int		len2;
	int		i;
	char	*layer;
	char	*layer_sum;

	len1 = strlen(a);
	len2 = strlen(b);
	len0 = (char *)malloc(sizeof(char) * len1 + len2 + 1);
	i = -1;
	while (++i < len2)
	{
		layer = calc_layer(a, b[len2 - 1 - i], i, base);
		layer_sum = comb_layer(layer_sum, layer);
	}
	return (trim_zero(layer_sum));
}

int		main(int argc, char **argv)
{
	char	*s;

	if (argc == 3)
	{
		s = ft_multiply(argv[1], argv[2], 10);
		ft_printf("%s\n", s);
	}
	return (0);
}
