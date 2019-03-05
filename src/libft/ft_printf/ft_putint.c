/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:07:19 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/20 16:07:21 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_sch(int n, t_struct flags, int len, int *len_res)
{
	if (n < 10)
		(*len_res) += ft_putchar_pr(n + '0');
	else
	{
		ft_putnbr_pr((n / 10), len_res);
		(*len_res) += ft_putchar_pr(n % 10 + '0');
	}
	if (flags.width > len && flags.minus)
	{
		n_time((flags.width - len), len_res, ' ');
	}
}

void	ft_putschar(int n, t_struct flags, int *len_res)
{
	int j;
	int nb;
	int len;

	flags.sp = 'd';
	nb = n;
	j = 1;
	len = 0;
	if (n < 0)
	{
		nb = -nb;
		flags.plus = 100;
	}
	len += a_len(nb, 10, len, (long long *)&j);
	if_flags_d(flags, &len, len_res);
	if (n < 0)
	{
		(*len_res) += ft_putchar_pr('-');
		len++;
	}
	else if (n >= 0 && flags.plus && !flags.nul && !flags.minus &&\
	flags.precision != -1 >= flags.width)
		(*len_res) += ft_putchar_pr('+');
	print_sch(nb, flags, len, len_res);
}
