/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:10:50 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/10 14:30:27 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t r;

	i = 0;
	j = 0;
	r = ft_strlen(src) + ft_strlen(dst);
	if (dstsize < (ft_strlen(dst) + 1))
		return (ft_strlen(src) + dstsize);
	while (dst[i])
		i++;
	while (i < (dstsize - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (r);
}
