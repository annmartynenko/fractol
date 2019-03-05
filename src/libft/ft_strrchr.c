/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:23:04 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/10 11:02:13 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while (s[i] != '\0')
		i++;
	while (s[i] != a && i != 0)
		i--;
	if (i == 0 && s[i] != a)
		return (NULL);
	else if (a == '\0')
		return ((char*)&s[i]);
	return ((char*)&s[i]);
}
