/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:03:15 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/11 12:23:58 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *a;

	if (alst && (*alst) && del)
	{
		while ((*alst) != NULL)
		{
			a = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free((*alst));
			(*alst) = a;
		}
		(*alst) = NULL;
	}
}
