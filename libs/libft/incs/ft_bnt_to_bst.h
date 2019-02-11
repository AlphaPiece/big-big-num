/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bnt_to_bst.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:00:46 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:31:33 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BNT_TO_BST_H
# define FT_BNT_TO_BST_H

# include "libft.h"

# define MAXNODE	1000

typedef struct s_btree	t_btree;

/*
** TYPE int
*/

void	push_int_arr(void *data);
void	*pop_int_arr(void *data);
int		cmp_int(int i, int j);
void	swap_int(int i, int j);

/*
** TYPE long
*/

void	push_long_arr(void *data);
void	*pop_long_arr(void *data);
int		cmp_long(int i, int j);
void	swap_long(int i, int j);

/*
** TYPE str
*/

void	push_str_arr(void *data);
void	*pop_str_arr(void *data);
int		cmp_str(int i, int j);
void	swap_str(int i, int j);

/*
** SORTING
*/

t_btree	*ft_bnt_to_bst(t_btree *bnt, int node_amt, char *data_type);

#endif
