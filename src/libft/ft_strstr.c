/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:59:56 by amartyne          #+#    #+#             */
/*   Updated: 2018/03/29 13:39:49 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		k = i;
		while (s2[j] == s1[k] && s2[j] != '\0')
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
