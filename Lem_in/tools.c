/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:56:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/01/30 11:56:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_put_error(char *str)
{
	(void)str;
	ft_putstr_fd("ERROR\n", 1);
	exit(1);
}

/*
**	ft_putstr(str);
**	ft_putstr("\n");
*/

void	ft_perror(void)
{
	perror("ERROR");
	exit(1);
}

void	ft_put_info(t_info *info)
{
	t_info		*start;

	start = info;
	while (start)
	{
		ft_printf("%s\n", start->line);
		start = start->next;
	}
	ft_printf("\n");
}

int		ft_isdigit_str(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int		ft_isprint_str(char *str)
{
	while (*str)
	{
		if (ft_isascii(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
