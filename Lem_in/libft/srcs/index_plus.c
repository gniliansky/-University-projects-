/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:27:29 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/20 12:27:45 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_plus(t_print *buf, char *str)
{
	char	*arr;

	if (str && buf && buf->plus == 1 && str[0] != '-' && str[0] != '+')
	{
		if ((arr = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
			return (NULL);
		ft_strcpy(arr + 1, str);
		arr[0] = '+';
		if (str)
			free(str);
		return (arr);
	}
	return (str);
}

char	*ft_add_plus_point(t_print *buf, char *str)
{
	char	*arr;

	if (str && buf && (buf->plus == 1 || str[0] == '-'))
	{
		if ((arr = ft_strnew(ft_strlen(str) + 1)) == NULL)
			return (str);
		ft_strcpy(arr + 1, str);
		if (str[0] == '-')
		{
			arr[0] = '-';
			arr[1] = '0';
		}
		if (str[0] != '-')
			arr[0] = '+';
		if (str)
			free(str);
		return (arr);
	}
	return (str);
}
