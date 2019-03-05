/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:17:09 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/04 12:04:02 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char*)malloc(size + 1);
	if (!a)
		return (NULL);
	while (i < size + 1)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
