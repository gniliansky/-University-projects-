/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:59:08 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/15 10:59:12 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print		*ft_creat_struct(void)
{
	t_print		*arr;

	arr = NULL;
	if ((arr = (t_print*)malloc(sizeof(t_print))))
	{
		arr->grille = 0;
		arr->zero = 0;
		arr->plus = 0;
		arr->minus = 0;
		arr->space = 0;
		arr->width = 0;
		arr->point = 0;
		arr->point_index = 0;
		arr->size = '\0';
		arr->index = '\0';
	}
	return (arr);
}

static void			ft_find_width(t_print *arr, char *buf)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (buf[i])
	{
		if (buf[i] == '.')
		{
			arr->point = ft_atoi_printf(buf + (i++ + 1));
			arr->point_index = 1;
			while (buf[i] >= '0' && buf[i] <= '9')
				i++;
		}
		else if (buf[i] >= '0' && buf[i] <= '9')
		{
			width = ft_atoi_printf(buf + i);
			if (width != 0)
				arr->width = width;
			while (buf[i] >= '0' && buf[i] <= '9')
				i++;
		}
		else
			i++;
	}
}

static void			ft_add_struct_int(t_print *arr, int *i, char *buf)
{
	if (arr && i && buf)
	{
		while (buf[*i])
		{
			if (buf[*i] == '#')
				arr->grille = 1;
			if (buf[*i] == '0' && (buf[(*i) - 1] < '1' || buf[(*i) - 1] > '9')
													&& buf[(*i) - 1] != '.')
				arr->zero = 1;
			if (buf[*i] == '+')
				arr->plus = 1;
			if (buf[*i] == '-')
				arr->minus = 1;
			if (buf[*i] == ' ')
				arr->space = 1;
			(*i)++;
		}
		ft_find_width(arr, buf);
	}
}

static void			ft_add_struct_size(char *size, int *i, char *buf)
{
	if (i && buf)
	{
		while (buf[*i])
		{
			if (buf[*i] == 'j')
				*size = 'j';
			if (buf[*i] == 'z' && *size != 'j')
				*size = 'z';
			if (buf[*i] == 'l' && (buf[(*i) + 1] == 'l' ||
				(buf[(*i) + 1] == ' ' && buf[(*i) + 2] == 'l'))
				&& *size != 'z' && *size != 'j')
				*size = 'L';
			if (buf[*i] == 'l' && *size != 'L' && *size != 'z' &&
														*size != 'j')
				*size = 'l';
			if (buf[*i] == 'h' && (buf[(*i) + 1] == 'h' || (buf[(*i) + 1]
				== ' ' && buf[(*i) + 2] == 'h')) && *size != 'l' &&
				*size != 'L' && *size != 'z' && *size != 'j')
				*size = 'H';
			if (buf[*i] == 'h' && *size != 'H' && *size != 'l' &&
					*size != 'L' && *size != 'z' && *size != 'j')
				*size = 'h';
			(*i)++;
		}
	}
}

t_print				*ft_add_index(char *buf, int index)
{
	t_print		*arr;
	int			i;

	i = 0;
	arr = NULL;
	if ((arr = ft_creat_struct()) && buf)
	{
		ft_add_struct_int(arr, &i, buf);
		i = 0;
		ft_add_struct_size(&(arr->size), &i, buf);
		arr->index = buf[index];
	}
	return (arr);
}
