/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:48:20 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/11 13:00:03 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(t_list *lst)
{
	t_list *a;

	if (lst)
	{
		while (lst)
		{
			a = lst->next;
			free(lst->content);
			free(lst);
			lst = a;
		}
		lst = NULL;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *r;

	r = NULL;
	if (lst && f)
	{
		res = f(lst);
		r = res;
		if (!res)
			return (NULL);
		lst = lst->next;
		while (lst)
		{
			res->next = f(lst);
			if (!res->next)
			{
				del(r);
				return (NULL);
			}
			res = res->next;
			lst = lst->next;
		}
	}
	return (r);
}
