/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:19:10 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/13 19:20:12 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *arr)
{
	size_t	i;
	size_t	len;
	char	a;

	i = 0;
	len = ft_strlen(arr) - 1;
	while (i < len)
	{
		a = arr[i];
		arr[i] = arr[len];
		arr[len] = a;
		i++;
		len--;
	}
}
