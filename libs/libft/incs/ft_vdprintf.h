/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:43:53 by zwang             #+#    #+#             */
/*   Updated: 2018/10/26 13:58:55 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VDPRINTF_H
# define FT_VDPRINTF_H

# include <stdarg.h>
# include "libft.h"
# define STR_LEN 1000000

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define RESET 		"\x1B[0m"

typedef struct			s_strblock
{
	char				str[STR_LEN + 1];
	size_t				storage;
	struct s_strblock	*next;
}						t_strblock;

typedef struct			s_package
{
	char				collection[127];
	va_list				args;
	char				fmt_spfr;
	int					width;
	int					precision;
	t_strblock			*strchain;
	char				*part;
	size_t				part_len;
}						t_package;

typedef	struct			s_handler
{
	char				*fmt_spfr;
	void				(*handler)(t_package *, va_list);
}						t_handler;

/*
** LEAF
*/

intmax_t				modify_signed_integer(t_package *package,
												va_list args);
uintmax_t				modify_unsigned_integer(t_package *package,
												va_list args);

void					hash_handler(t_package *package, t_strblock *block,
										uintmax_t num);
void					sign_handler(t_package *package, t_strblock *block,
										intmax_t num);
void					int_precision_handler(t_package *package,
												t_strblock *block);
void					width_handler(t_package *package, t_strblock *block);
void					content_handler(t_package *package, t_strblock *block);

/*
** BRANCH
*/

void					string(t_package *package, va_list args);
void					signed_integer(t_package *package, va_list args);
void					unsigned_integer(t_package *package, va_list args);
void					character(t_package *package, va_list args);

/*
** CORE
*/

# define HANDLER_NUM 4

t_strblock				*create_strblock(void);
t_strblock				*find_last_block(t_strblock *strchain);
t_strblock				*append_new_strblock(t_strblock *strchain);

void					str_handler(t_strblock *strchain, const char *next_part,
									char *percent);

void					initialize_zero(char collection[128]);
int						is_conversion(char c);
int						is_flag(char c);
int						is_modifier(char c);
void					asterisk_handler(t_package *package, char *ptr, int *i,
											va_list args);
char					*flag_collector(t_package *package, char *fmt_ptr,
											va_list args);
char					*fmt_handler(t_package *package, char *fmt_ptr,
										va_list args);

/*
** ROOT
*/

int						ft_vdprintf(int fd, const char *format, va_list args);

#endif
