/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:13:32 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/11 14:20:33 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**check_do(char const *s, char c)
{
	int		i;
	int		n;
	char	**a;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	a = (char**)malloc(sizeof(char*) * n + 1);
	return (a);
}

static char		*get_str(int i, int j, char const *s, char **a)
{
	char	*str;

	if (!(str = ft_strsub(s, i, j - i)))
	{
		ft_arrfree(a);
		return (NULL);
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**a;
	int		n;
	int		j;

	i = 0;
	n = 0;
	j = 0;
	if (!s || !(a = check_do(s, c)))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (s[i])
			if (!(a[n++] = get_str(i, j, s, a)))
				return (NULL);
		i = j;
	}
	a[n] = 0;
	return (a);
}
