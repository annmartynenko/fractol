/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:00:39 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/10 14:26:50 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;

	i = 0;
	j = 0;
	a = NULL;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	a = (char*)malloc(l1 + l2 + 1);
	if (!a)
		return (NULL);
	while (i < l1)
	{
		a[i] = s1[i];
		i++;
	}
	while (j < l2)
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}
