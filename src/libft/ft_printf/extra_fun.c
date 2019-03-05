/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:01:40 by amartyne          #+#    #+#             */
/*   Updated: 2018/08/13 19:01:43 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	for_flags_unistr(t_struct flags, int *len_res, int *len, wchar_t *arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		*len += len_unco(count_bin((wchar_t)arr[i]));
		if (flags.precision != -1 && *len > flags.precision)
		{
			*len -= len_unco(count_bin((wchar_t)arr[i]));
			break ;
		}
		i++;
	}
	if (flags.width > *len && !flags.minus && flags.nul)
		n_time((flags.width - *len), len_res, '0');
	else if (flags.width > *len && !flags.minus && !flags.nul)
		n_time((flags.width - *len), len_res, ' ');
	else if (flags.width && !flags.minus && !flags.nul &&\
		flags.precision != -1 && flags.width > flags.precision)
		n_time((flags.width - *len), len_res, ' ');
	else if (flags.width && !flags.minus && !flags.nul &&\
		flags.precision == -1)
		n_time((flags.width), len_res, ' ');
	else if (flags.width && !flags.minus && flags.nul)
		n_time((flags.width), len_res, '0');
}

void	uni_str(wchar_t *arr, t_struct flags, int *len_res)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (arr)
	{
		len = 0;
		for_flags_unistr(flags, len_res, &len, arr);
		len = 0;
		if (flags.precision != 0)
		{
			while (arr[i])
			{
				len += len_unco(count_bin((wchar_t)arr[i]));
				if (flags.precision != -1 && len > flags.precision)
					break ;
				unicode(arr[i++], flags, 2, len_res);
			}
		}
		if (flags.width > len && flags.minus && !flags.nul)
			n_time((flags.width - len), len_res, ' ');
	}
	else
		*len_res += ft_putstr_pr("(null)");
}

void	n_time(int i, int *len_res, char str)
{
	int j;

	j = 0;
	if (i > 0)
	{
		while (j < i)
		{
			j++;
			*len_res += ft_putchar_pr(str);
		}
	}
}

int		len_unco(int size)
{
	int len;

	if (size <= 7)
		len = 1;
	else if (size <= 11)
		len = 2;
	else if (size <= 16)
		len = 3;
	else
		len = 4;
	return (len);
}
