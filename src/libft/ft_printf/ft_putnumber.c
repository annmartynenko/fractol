/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:39:56 by amartyne          #+#    #+#             */
/*   Updated: 2018/09/18 17:39:57 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_numb(long long n, t_struct flags, int len, int *len_res)
{
	if (n < 10)
		(*len_res) += ft_putchar_pr(n + '0');
	else
	{
		print_numb((n / 10), flags, len, len_res);
		(*len_res) += ft_putchar_pr(n % 10 + '0');
	}
}

void	if_n_low(long long n, t_struct *flags, int *len_res, long long *nb)
{
	if (n < 0)
	{
		(*nb) *= -1;
		(*flags).plus = 100;
	}
	if (*nb == -922337203685477580.8 * 10)
	{
		(*nb) = (*nb) % 1000000000000000000;
		(*nb) = -(*nb);
		(*len_res) += ft_putchar_pr('-');
		(*len_res) += ft_putchar_pr('9');
	}
}

void	ft_putnumber(long long int n, t_struct flags, int *len_res)
{
	long long	j;
	long long	nb;
	int			len;

	flags.sp = 'd';
	nb = n;
	j = 1;
	len = 0;
	if_n_low(n, &flags, len_res, &nb);
	len += a_len(nb, 10, 0, &j);
	flags = if_flags_d(flags, &len, len_res);
	if (n < 0 && ((!flags.nul && !flags.width && flags.precision == -1) ||\
	flags.minus || (flags.nul && !flags.width && flags.precision == -1)) &&\
	nb != 22337203685477580.8 * 10)
	{
		(*len_res) += ft_putchar_pr('-');
		len++;
	}
	else if (n >= 0 && flags.plus && !flags.nul && !flags.minus &&\
	flags.sp != 1)
		(*len_res) += ft_putchar_pr('+');
	if (nb != 0 || flags.precision != 0)
		print_numb(nb, flags, len, len_res);
	if (flags.width > len && flags.minus)
		n_time((flags.width - len), len_res, ' ');
}

void	print_max(intmax_t n, t_struct flags, int len, int *len_res)
{
	if (n < 10)
		(*len_res) += ft_putchar_pr((char)(n + '0'));
	else
	{
		ft_putmax(n / 10, flags, len_res);
		(*len_res) += ft_putchar_pr((char)(n % 10 + '0'));
	}
	if (flags.width > len && flags.minus && !flags.nul)
		n_time((flags.width - len), len_res, ' ');
}

void	ft_putmax(intmax_t n, t_struct flags, int *len_res)
{
	long long	j;
	intmax_t	nb;
	int			len;

	nb = n;
	j = 1;
	len = 0;
	if (n < 0)
	{
		nb = -nb;
		len++;
	}
	len = a_len(nb, 10, len, &j);
	if_flags(flags, len, len_res);
	if (n < 0)
		(*len_res) += ft_putchar_pr('-');
	print_max(nb, flags, len, len_res);
}
