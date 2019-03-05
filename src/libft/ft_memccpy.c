/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:02:34 by amartyne          #+#    #+#             */
/*   Updated: 2018/03/29 13:39:27 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,\
size_t n)
{
	unsigned char	d;
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	d = (unsigned char)c;
	while (i != n)
	{
		if (b[i] == d)
		{
			a[i] = b[i];
			a = a + i + 1;
			return (a);
		}
		else
			a[i] = b[i];
		i++;
	}
	return (NULL);
}
