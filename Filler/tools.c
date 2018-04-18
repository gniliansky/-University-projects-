/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:11:03 by vgnylyan          #+#    #+#             */
/*   Updated: 2017/12/25 09:11:05 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_printarr(char **arr)
{
	int i;

	i = 0;
	if (arr)
		while (arr[i])
		{
			ft_putendl(arr[i]);
			i++;
		}
}

char	**ft_free_arr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
