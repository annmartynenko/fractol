/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:32:28 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/11 13:08:50 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int *ints;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	else
	{
		ints = (int*)malloc(sizeof(int) * (max - min));
		if (!ints)
			return (0);
		while (min != max)
		{
			ints[i] = min;
			i++;
			min++;
		}
		return (ints);
	}
}
