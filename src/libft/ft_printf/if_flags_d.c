/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_flags_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:44:48 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/11 16:44:49 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			if_flags_d2(t_struct *flags, int *len, int *len_res)
{
	if ((*flags).width > (*len) && (*flags).nul && !(*flags).minus &&\
	(*flags).precision == -1 && !(*flags).space)
	{
		if ((*flags).plus == '+')
		{
			(*len)++;
			(*len_res) += ft_putchar_pr('+');
		}
		else if ((*flags).plus == 100)
		{
			(*len)++;
			(*len_res) += ft_putchar_pr('-');
		}
		n_time(((*flags).width - (*len)), len_res, '0');
	}
	else if ((*flags).width > (*len) && !(*flags).nul &&\
	(*flags).plus != 100 &&\
	!(*flags).minus && (*flags).precision == -1)
	{
		if ((*flags).plus)
			(*len)++;
		n_time(((*flags).width - (*len)), len_res, ' ');
		if ((*flags).plus)
			(*len_res) += ft_putchar_pr('+');
	}
}

void			if_flags_d3(t_struct *flags, int *len, int *len_res)
{
	if ((*flags).width > (*len) && !(*flags).minus && !(*flags).nul && \
	(*len) > (*flags).precision)
	{
		if ((*flags).plus == 100)
			(*len)++;
		if ((*flags).precision == 0)
			(*len) = 0;
		n_time(((*flags).width - (*len)), len_res, ' ');
		if ((*flags).plus == 100)
			(*len_res) += ft_putchar_pr('-');
	}
	else if ((*flags).width > (*len) && (*flags).precision != -1 && \
	(*flags).width > (*flags).precision && !(*flags).minus)
	{
		(*flags).sp = 0;
		if (((*flags).plus && (*flags).plus != 100) || (*flags).plus == 100)
			(*flags).sp = 1;
		n_time(((*flags).width - (*flags).precision - (*flags).sp),\
		len_res, ' ');
		if ((*flags).plus == 100)
			(*len_res) += ft_putchar_pr('-');
		if ((*flags).plus && (*flags).plus != 100)
			(*len_res) += ft_putchar_pr('+');
		n_time(((*flags).precision - (*len)), len_res, '0');
	}
}

void			if_flags_d4(t_struct *flags, int *len, int *len_res)
{
	if ((*flags).width > (*len) && (*flags).width <= (*flags).precision)
	{
		if ((*flags).plus == 100)
			(*len_res) += ft_putchar_pr('-');
		if ((*flags).space)
			(*len_res) += ft_putchar_pr(' ');
		n_time(((*flags).precision - (*len)), len_res, '0');
	}
	else if ((*flags).width > (*len) && (*flags).nul && !(*flags).minus)
	{
		if ((*flags).space)
		{
			(*len_res) += ft_putchar_pr(' ');
			(*len)++;
		}
		n_time(((*flags).width - (*len)), len_res, '0');
	}
}

void			if_flags_d5(t_struct *flags, int *len, int *len_res)
{
	if ((*flags).precision != -1)
	{
		if ((*flags).space)
		{
			(*len)++;
			(*len_res) += ft_putchar_pr(' ');
		}
		if ((*flags).plus && (*flags).plus != 100)
			(*len_res) += ft_putchar_pr('+');
		else if ((*flags).plus && (*flags).plus == 100)
			(*len_res) += ft_putchar_pr('-');
		n_time(((*flags).precision - (*len)), len_res, '0');
		(*len) += (*flags).precision - (*len);
		if ((*flags).plus)
			(*len) += 1;
	}
	else if ((*flags).space && (*flags).sp == 'd' && !(*flags).plus\
	&& !(*flags).minus)
		(*len_res) += ft_putchar_pr(' ');
	else if ((*flags).plus != 100 && (*flags).plus && (*flags).nul)
		(*len_res) += ft_putchar_pr('+');
}

t_struct		if_flags_d(t_struct flags, int *len, int *len_res)
{
	if ((flags.width > (*len) && flags.nul && !flags.minus &&\
	flags.precision == -1 && !flags.space) || ((flags).width > (*len) &&\
	!(flags).nul && (flags).plus != 100 && !(flags).minus &&\
	(flags).precision == -1))
		if_flags_d2(&flags, len, len_res);
	else if (((flags).width > (*len) && !(flags).minus && !(flags).nul && \
	(*len) > (flags).precision) || ((flags).width > (*len) &&\
	(flags).precision != -1 && (flags).width > (flags).precision\
	&& !(flags).minus))
		if_flags_d3(&flags, len, len_res);
	else if (((flags).width > (*len) && (flags).width <= (flags).precision) ||\
	((flags).width > (*len) && (flags).nul && !(flags).minus))
		if_flags_d4(&flags, len, len_res);
	else if (((flags).precision != -1) || ((flags).space &&\
	(flags).sp == 'd' && !(flags).plus && !(flags).minus) ||\
	((flags).plus != 100 && (flags).plus && (flags).nul))
		if_flags_d5(&flags, len, len_res);
	return (flags);
}
