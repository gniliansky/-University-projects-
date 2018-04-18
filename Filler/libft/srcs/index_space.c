/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:32:30 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/20 12:32:44 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_swap_string_space(char *str)
{
	int len;

	if (str == NULL)
		return ;
	len = ft_strlen(str) - 1;
	while (len > 0)
	{
		str[len] = str[len - 1];
		len--;
	}
	str[0] = ' ';
}

char			*ft_space(t_print *buf, char *str)
{
	char *arr;

	if (buf && str && buf->space == 1)
	{
		if (str[0] == '0' && str[1] == '0')
			str[0] = ' ';
		else if (ft_strchr(str, ' ') == NULL && str[0] != '-' && str[0] != '+')
		{
			if ((arr = ft_strnew(ft_strlen(str) + 1)) == NULL)
				return (str);
			ft_strcpy(arr + 1, str);
			arr[0] = ' ';
			if (str)
				free(str);
			return (arr);
		}
		else if (ft_strchr(str, ' ') != NULL && str[0] != '-' && str[0] != '+')
			if (str[0] >= '0' && str[0] <= '9')
				ft_swap_string_space(str);
	}
	return (str);
}
