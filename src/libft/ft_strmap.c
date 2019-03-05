/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:56:05 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/09 20:03:32 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	int		i;

	i = 0;
	a = NULL;
	if (s && f)
	{
		a = (char*)malloc(ft_strlen(s) + 1);
		if (!a)
			return (NULL);
		while (s[i])
		{
			a[i] = f(s[i]);
			i++;
		}
		a[i] = '\0';
	}
	return (a);
}
