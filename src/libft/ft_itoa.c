/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:55:26 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/11 12:19:18 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*mem(int len, long int nb, int j, int n)
{
	char *a;

	a = (char*)malloc(sizeof(char) * len + 1);
	if (!a)
		return (0);
	len = 0;
	if (n < 0)
		a[len++] = '-';
	while (j >= 1)
	{
		a[len++] = nb / j + '0';
		nb = nb % j;
		j = j / 10;
	}
	a[len] = '\0';
	return (a);
}

char			*ft_itoa(int n)
{
	int			j;
	long int	nb;
	int			len;
	char		*a;

	j = 1;
	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len = 1;
	}
	while (nb / j >= 10)
	{
		len++;
		j = j * 10;
	}
	len = len + 1;
	a = mem(len, nb, j, n);
	return (a);
}
