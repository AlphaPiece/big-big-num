/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:44:39 by zwang             #+#    #+#             */
/*   Updated: 2018/11/01 11:23:03 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NEXTLINE_H
# define FT_NEXTLINE_H

# include "libft.h"
# define BUFF_SIZE 512
# define NL_INDEX (nlc - buffer)
# define MALLOC_FREE(x, y, z) x = y; y = z; free(x);

typedef	struct		s_file
{
	int				fd;
	char			*save;
	struct s_file	*next;
}					t_file;

int					ft_nextline(const int fd, char **line);

#endif
