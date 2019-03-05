/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:51:39 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/09 19:59:14 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	a = (char*)malloc(len + 1);
	if (a)
	{
		while (i < len)
		{
			a[i] = s[start];
			i++;
			start++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
