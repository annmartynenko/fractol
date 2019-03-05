/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:55:49 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/11 13:04:03 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *a;

	a = (t_list*)malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	if (content == NULL)
	{
		a->content = NULL;
		a->content_size = 0;
		a->next = NULL;
		return (a);
	}
	a->content = (void*)malloc(content_size);
	if (!(a->content))
	{
		free(a);
		return (NULL);
	}
	a->content = ft_memcpy(a->content, content, content_size);
	a->content_size = content_size;
	a->next = NULL;
	return (a);
}
