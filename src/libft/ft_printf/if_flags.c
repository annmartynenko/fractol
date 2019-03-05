/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:16:35 by amartyne          #+#    #+#             */
/*   Updated: 2018/09/15 16:16:38 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			if_flags2(t_struct flags, int len, int *len_res)
{
	if (flags.width > len && flags.width <= flags.precision)
	{
		if (flags.space)
			(*len_res) += ft_putchar_pr(' ');
		n_time((flags.precision - len), len_res, '0');
	}
	else if (flags.width > len && flags.nul && !flags.minus)
	{
		if (flags.space)
		{
			(*len_res) += ft_putchar_pr(' ');
			len++;
		}
		n_time((flags.width - len), len_res, '0');
	}
	else if (flags.precision != -1)
	{
		if (flags.space)
			(*len_res) += ft_putchar_pr(' ');
		n_time((flags.precision - len), len_res, '0');
	}
	else if (flags.space && flags.sp == 'd' && !flags.plus)
		(*len_res) += ft_putchar_pr(' ');
}

void			if_flags(t_struct flags, int len, int *len_res)
{
	if (flags.width > len && flags.nul && !flags.minus && flags.plus)
	{
		(*len_res) += ft_putchar_pr('+');
		n_time((flags.width - len - 1), len_res, '0');
	}
	else if (flags.width > len && !flags.nul && flags.plus && !flags.minus)
	{
		n_time((flags.width - len - 1), len_res, ' ');
		(*len_res) += ft_putchar_pr('+');
	}
	else if (flags.width > len && !flags.minus && !flags.nul && \
	len > flags.precision)
		n_time((flags.width - len), len_res, ' ');
	else if (flags.width > len && flags.precision != -1 && \
	flags.width > flags.precision && !flags.minus)
	{
		n_time((flags.width - flags.precision), len_res, ' ');
		n_time((flags.precision - len), len_res, '0');
	}
	else
		if_flags2(flags, len, len_res);
}
