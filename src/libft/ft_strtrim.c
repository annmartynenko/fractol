/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:30:55 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/09 19:57:53 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*a;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i])
	{
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
	}
	n = len - i + 1;
	a = (char*)malloc(n);
	if (!a)
		return (NULL);
	len = 0;
	while (len < n - 1)
		a[len++] = s[i++];
	a[len] = '\0';
	return (a);
}
