/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:38:33 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/10 11:36:50 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		k = i;
		while (s2[j] == s1[k] && s2[j] != '\0' && k < len)
		{
			j++;
			k++;
		}
		if (s2[j] == '\0')
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
