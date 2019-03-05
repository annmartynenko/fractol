/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:08:31 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/09 20:54:20 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				res;
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	i = 0;
	res = 0;
	if (s1 && s2)
	{
		while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i])
			i++;
		if (a[i] != b[i])
			res = a[i] - b[i];
	}
	return (res);
}
