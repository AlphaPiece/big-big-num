/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:15:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/18 20:08:14 by Zexi Wang        ###   ########.fr       */
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
}						t_bignum;

typedef struct			s_compo
{
	int					x;
	int					e10;
	struct s_compo		*next;
}						t_compo;


t_numpart				*create_part(int val);
void					prepend_part(t_bignum *num, t_numpart *part);
void					append_part(t_bignum *num, t_numpart *part);
void					remove_front_part(t_bignum *num);
void					remove_back_part(t_bignum *num);

t_bignum				*create_num(void);
t_bignum				*copy_num(t_bignum *num);
int						get_part_no(t_bignum *num);
void					delete_num(t_bignum **num);
void					print_num(t_bignum *num);

t_compo					*create_compo(int n, int e10);
void					append_compo(t_compo **head, t_compo *new_compo);
t_compo					*get_compo_lst(t_bignum *num);
void					delete_compo_lst(t_compo **compo_head);

void					convert(char *s, int len, t_bignum *bn);
void					left_shift(t_bignum *num, int shift);
void					right_shift(t_bignum *num, int shift);

void					add(t_bignum *n1, t_bignum *n2);
void					subtract(t_bignum *n1, t_bignum *n2);
t_bignum				*multiply(t_bignum *n1, t_bignum *n2);

#endif
