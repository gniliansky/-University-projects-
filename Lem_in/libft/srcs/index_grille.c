/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fotmat_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:34:28 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/12 14:34:30 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_grille(t_print *buf, char *str)
{
	char	*arr;

	arr = NULL;
	if (buf == NULL && str == NULL)
		return (str);
	if (buf->grille == 1 && (buf->index == 'o' || buf->index == 'O'))
	{
		arr = ft_add_zerox(str, '0');
		if (arr)
			return (arr);
	}
	else if (buf->grille == 1)
	{
		if (buf->index == 'o' || buf->index == 'O')
			arr = ft_add_zerox(str, '0');
		if (buf->index == 'x')
			arr = ft_add_zerox(str, 'x');
		if (buf->index == 'X')
			arr = ft_add_zerox(str, 'X');
		if (arr)
			return (arr);
	}
	return (str);
}
