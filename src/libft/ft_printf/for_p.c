/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:35:11 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/05 15:35:12 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	for_p2(t_struct flags, int len, int *len_res)
{
	if (!flags.minus && !flags.nul && flags.precision != -1)
		*len_res += ft_putstr_pr("0x");
	else if (flags.precision == -1 && !flags.width && !flags.hash &&\
	!flags.minus && !flags.nul)
		*len_res += ft_putstr_pr("0x");
	else if (flags.width && flags.nul)
	{
		*len_res += ft_putstr_pr("0x");
		n_time(flags.width - len - 2, len_res, '0');
	}
	else if (flags.width)
	{
		n_time(flags.width - len - 2, len_res, ' ');
		*len_res += ft_putstr_pr("0x");
	}
}

int		for_p(t_struct flags, int len)
{
	int len_res;

	len_res = 0;
	if (flags.width > flags.precision && flags.precision != -1 &&\
	flags.width > len && flags.width)
	{
		n_time((flags.width - len - 2), &len_res, ' ');
		len_res += ft_putstr_pr("0x");
	}
	else if (flags.width < flags.precision && flags.precision != -1 &&\
	flags.width)
	{
		len_res += ft_putstr_pr("0x");
		n_time((flags.precision - len), &len_res, '0');
	}
	else if (flags.precision != -1 && flags.precision > len)
	{
		len_res += ft_putstr_pr("0x");
		n_time((flags.precision - 1), &len_res, '0');
	}
	else
		for_p2(flags, len, &len_res);
	return (len_res);
}
