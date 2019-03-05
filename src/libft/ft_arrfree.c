/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:27:27 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/10 14:27:29 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrfree(char **s)
{
	int i;

	i = 0;
	if (s && (*s))
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

void	ft_arrfree_int(int **s)
{
	int i;

	i = 0;
	if (s && (*s))
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}
