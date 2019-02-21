/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:15:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/02/21 10:17:41 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNC_H
# define BNC_H

# include "libft.h"

# define PART_LEN		4
# define STACK_SPACE	1000
# define ERROR			0
# define NORM			1

# define IS_OP(x)	(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')

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
	t_bool				is_neg;
	t_bool				is_zero;
}						t_bignum;

typedef struct			s_compo
{
	int					x;
	int					e10;
	struct s_compo		*next;
}						t_compo;

/*
** CORE
*/

t_numpart				*create_part(int val);
void					prepend_part(t_bignum *num, t_numpart *part);
void					append_part(t_bignum *num, t_numpart *part);
void					remove_front_part(t_bignum *num);
void					remove_back_part(t_bignum *num);

t_bignum				*create_num(void);
t_bignum				*init_num(int val);
t_bignum				*copy_num(t_bignum *num);
void					remove_leading_zero(t_bignum *num);
void					delete_num(t_bignum **num);

int						get_part_no(t_bignum *num);
int						get_digit_no(t_bignum *num);
int						compare_num(t_bignum *n1, t_bignum *n2);
t_bool					same_sign(t_bignum *n1, t_bignum *n2);
void					print_num(t_bignum *num);


t_compo					*create_compo(int n, int e10);
void					append_compo(t_compo **head, t_compo *new_compo);
t_compo					*get_compo_lst(t_bignum *num);
t_bignum				*revert_compo_lst(t_compo *compo_head);
void					delete_compo_lst(t_compo **compo_head);

t_bignum				*convert(char *s, int len);
void					left_shift(t_bignum *num, int shift);
void					right_shift(t_bignum *num, int shift);

void					add(t_bignum *n1, t_bignum *n2);
void					subtract(t_bignum *n1, t_bignum *n2);
t_bignum				*multiply(t_bignum *n1, t_bignum *n2);
t_bignum				*divide(t_bignum *n1, t_bignum *n2);
void					modulo(t_bignum *n1, t_bignum *n2);

/*
** INTERFACE
*/

t_bool					numstack_empty(void);
int						push_num(t_bignum *num);
t_bignum				*pop_num(void);
int						numstack_num_no(void);
void					clear_numstack(void);

t_bool					opstack_empty(void);
int						push_op(char op);
char					pop_op(void);
char					check_top_op(void);
void					clear_opstack(void);

int						precedence(char op);
t_bignum				*apply_op(char op, t_bignum **n1, t_bignum **n2);
int						parse_expr(char *expr);

void					compute(void);

void					print_numstack(void);
void					print_opstack(void);

#endif
