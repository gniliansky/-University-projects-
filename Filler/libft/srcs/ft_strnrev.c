/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:29:04 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/11/13 19:59:42 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strnrev(char *arr, size_t start, size_t end)
{
	char a;

	if (arr == NULL || start > ft_strlen(arr))
		return ;
	if (end > ft_strlen(arr))
		end = ft_strlen(arr) - 1;
	while (start < end)
	{
		a = arr[start];
		arr[start] = arr[end];
		arr[end] = a;
		start++;
		end--;
	}
}
