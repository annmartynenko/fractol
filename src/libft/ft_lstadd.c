/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:21:34 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/11 12:10:37 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && (*alst) && new)
	{
		new->next = (*alst);
		(*alst) = new;
	}
	if ((*alst) == NULL && new)
		(*alst) = new;
}
