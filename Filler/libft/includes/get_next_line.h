/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:41:25 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/01 19:51:31 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 64

struct				s_line
{
	int				fd;
	int				finish;
	char			buf[BUFF_SIZE + 1];
	struct s_line	*next;
};

int					get_next_line(const int fd, char **line);

#endif
