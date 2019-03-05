/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:49:24 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/23 17:49:26 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		a_len(long long n, int base, int len, long long *j)
{
	while (n / (*j) >= base)
	{
		len++;
		(*j) *= base;
	}
	len++;
	return (len);
}

int		fill(unsigned base, unsigned long long n, long long j, int letter)
{
	char	symbols[16];
	int		len_res;

	len_res = 0;
	if (letter == 1)
		ft_memcpy(symbols, "0123456789ABCDEF", 16);
	else
		ft_memcpy(symbols, "0123456789abcdef", 16);
	if (letter == 3)
		len_res += ft_putstr_pr("0x");
	while (j >= 1)
	{
		if (n / j <= base)
			len_res += ft_putchar_pr(symbols[n / j]);
		n %= j;
		j /= base;
	}
	return (len_res);
}

int		unsigned_len(long long n, unsigned base, int len,\
unsigned long long *j)
{
	while (n / (*j) >= base)
	{
		len++;
		(*j) *= base;
	}
	len++;
	return (len);
}

int		ft_itoa_base_pr(long long n, int base, int letter, t_struct flags)
{
	int					len;
	long long			nb;
	unsigned long long	j;
	int					len_res;

	j = 1;
	len_res = 0;
	nb = n;
	len = unsigned_len(nb, (unsigned)base, 0, &j);
	if (n == 0 && letter != P)
		letter = -1;
	if (letter == P && flags.minus)
	{
		len += 2;
		letter = 3;
	}
	len_res += if_flags_ito(flags, len, base, letter);
	if (flags.precision != 0)
		len_res += fill((unsigned)base, nb, j, letter);
	for_minus(flags, len, base, &len_res);
	return (len_res);
}
