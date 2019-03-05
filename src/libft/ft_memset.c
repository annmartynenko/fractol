/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:08:31 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/03 16:30:51 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	d;
	size_t			i;

	i = 0;
	a = (unsigned char*)b;
	d = (unsigned char)c;
	while (i != len)
	{
		a[i] = d;
		i++;
	}
	return (a);
}
