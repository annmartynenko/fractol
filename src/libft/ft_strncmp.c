/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:46:38 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/10 11:45:41 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*a;
	unsigned char	*b;

	res = 0;
	i = 0;
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	while (a[i] == b[i] && i < n && a[i] != '\0' && b[i] != '\0')
	{
		i++;
	}
	if (a[i] != b[i] && i < n)
		res = a[i] - b[i];
	return (res);
}
