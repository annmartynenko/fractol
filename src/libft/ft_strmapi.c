/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:10:49 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/09 20:04:28 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*a;

	i = 0;
	a = NULL;
	if (s && f)
	{
		a = (char*)malloc(ft_strlen(s) + 1);
		if (a)
		{
			while (s[i])
			{
				a[i] = f(i, s[i]);
				i++;
			}
			a[i] = '\0';
		}
	}
	return (a);
}
