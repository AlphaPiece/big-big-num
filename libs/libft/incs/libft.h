/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:20:28 by zwang             #+#    #+#             */
/*   Updated: 2019/04/12 10:56:03 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdint.h>
# include <time.h>
# include "ft_nextline.h"
# include "ft_vdprintf.h"

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef enum		e_state
{
	OUT,
	IN
}					t_state;

/*
** ==============
** >            <
** >>> MEMORY <<<
** >            <
** ==============
*/

/*
** ARRLEN:	len of an array; only for stack array
** BYTE:	# of bit for a byte
** WORD:	# of bit for a word
** BIT8:	# of byte for type uint8_t
** BIT16:	# of byte for type uint16_t
** BIT32:	# of byte for type uint32_t
** BIT64:	# of byte for type uint64_t
*/

# define ARRLEN(a)	(sizeof(a) / sizeof(a[0]))
# define BYTE		8
# define WORD		32
# define BIT8		(sizeof(uint8_t))
# define BIT16		(sizeof(uint16_t))
# define BIT32		(sizeof(uint32_t))
# define BIT64		(sizeof(uint64_t))

typedef union		u_uint
{
	uint8_t			uint8;
	uint16_t		uint16;
	uint32_t		uint32;
	uint64_t		uint64;
}					t_uint;

typedef union		u_ptr
{
	uint8_t			*uint8p;
	uint16_t		*uint16p;
	uint32_t		*uint32p;
	uint64_t		*uint64p;
}					t_ptr;

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memfree(void **ptr);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
unsigned int		ft_getbits(unsigned int x, int p, int n);
unsigned int		ft_setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int		ft_invertbits(unsigned int x, int p, int n);
void				ft_memswap(void *p1, void *p2, size_t byte);
void				*ft_memrealloc(void **ptr, size_t oldsize, size_t newsize);
void				ft_putbits(void *x, size_t bit);

/*
** ==============
** >            <
** >>> NUMBER <<<
** >            <
** ==============
*/

/*
** F_PREC:	double float decimal digits of precision
** ABS:		absolute value
*/

# define F_PREC	15	

# define ABS(x)	(((x) < 0) ? -(x) : (x))

/*
** t_fcompo:	contains all the parts of a single float type data
** sign:		1 bit (0)
** exponent:	8 bits (1 ~ 8) (the exponent of 2)
** mantissa:	23 bits (9 ~ 31) (the presence of 2's power: 2^-1, 2^-2, ...)
*/

typedef struct		s_fcompo
{
	int				sign;
	int				exponent;
	long			mantissa;
}					t_fcompo;

int					ft_numlen(intmax_t n);
int					ft_unumlen(uintmax_t un);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_ntoa(intmax_t n);
char				*ft_untoa(uintmax_t un);
char				*ft_ntoa_base(intmax_t n, int base, char hex_case_a);
char				*ft_untoa_base(uintmax_t un, int base, char hex_case_a);
char				*ft_ftoa(double n);
double				ft_sqrt(double n);
double				ft_pow(double n, int pow);
void				ft_prime_factors(int n);
double				ft_ceil(double n);
double				ft_floor(double n);
t_fcompo			*ft_analyze_float(float n);
int					*ft_numarrcpy(int *dst, const int *src, size_t len);
t_bool				ft_iselem(size_t byte, void *arr, size_t len, void *num);
int					ft_max(int total_no, ...);
int					ft_min(int total_no, ...);
int					ft_sum(int total_no, ...);
int					ft_intarrmax(int arr[], int len);
int					ft_intarrmin(int arr[], int	len);
int					ft_intarrsum(int arr[], int len);
int                 *ft_randintarr(int lower, int upper, int len);
long long			ft_factorial(int n);
long long			ft_fibonacci(int n);
long long			ft_uglynum(int n);
void				ft_swap(int *a, int *b);

/*
** =======================
** >                     <
** >>> ASCII CHARACTER <<<
** >                     <
** =======================
*/

t_bool				ft_isalnum(int c);
t_bool				ft_isalpha(int c);
t_bool				ft_isascii(int c);
t_bool				ft_isdigit(int c);
t_bool				ft_isspace(int c);
t_bool				ft_isprint(int c);
t_bool				ft_islower(int c);
t_bool				ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** ==============================
** >                            <
** >>> ASCII CHARACTER STRING <<<
** >                            <
** ==============================
*/

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
double				ft_atof(const char *str);
int					ft_atoi_base(const char *str, int base);
long				ft_atol_base(const char *str, int base);
t_bool				ft_isnumeric(char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strclen(const char *s, char *delim);
int					ft_strsepnum(const char *s, char *delim);
int					ft_count_subs(const char *str, const char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
t_bool				ft_strequ(const char *s1, const char *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
t_bool				ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(const char *s, char *delim);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				*ft_strcapitalize(char *s);
t_bool				ft_check_brackets(const char *s);
size_t				ft_strarrlen(const char *arr[]);
char				**ft_strarrdup(char *dst[], const char *src[]);
void				ft_strarrdel(char *arr[]);
t_bool				ft_strstart(const char *str, const char *substr);
t_bool				ft_strend(const char *str, const char *substr);
void				ft_strsqueeze(char str[], int c);
void				ft_strarrsort(char *arr[], int len,
									int (*cmp)(const char *, const char *));
char				*ft_strcompose(int str_num, ...);

/*
** =========================
** >                       <
** >>> FILE INPUT/OUTPUT <<<
** >                       <
** =========================
*/

# define BUF_SIZ	1024

void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putnchar_fd(char c, int n, int fd);
void				ft_putnchar(char c, int n);
void				ft_putncharln(char c, int n);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstr(const char *s);
void				ft_putlstr_fd(const char *str, unsigned int start,
									size_t len, int fd);
void				ft_putlstr(const char *str, unsigned int start,
								size_t len);
int					ft_getchar(void);
int					ft_getonechar(void);
int					ft_nextchar(void);
void				ft_savechar(int c);
int					ft_nextword(char *word, int limit);
int					ft_vdprintf(int fd, const char *format, va_list args);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_nextline(const int fd, char **line);

#endif
