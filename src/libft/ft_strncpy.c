/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:43:34 by amartyne          #+#    #+#             */
/*   Updated: 2018/03/29 13:33:34 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t a;

	i = 0;
	a = ft_strlen(src);
	while (i != len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (a < len)
	{
		a = i;
		while (a != len)
		{
			dst[a] = '\0';
			a++;
		}
	}
	return (dst);
}
