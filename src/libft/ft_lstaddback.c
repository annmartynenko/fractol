/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:14:49 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/16 15:43:22 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list *alst, t_list *new)
{
	if (alst && new)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
	}
}
