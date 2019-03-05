/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unslong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:12:01 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/11 18:12:03 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		fill_uns(unsigned long base, unsigned long n, unsigned long j,\
int letter)
{
	char	symbols[16];
	int		len_res;

	len_res = 0;
	if (letter == 1)
		ft_memcpy(symbols, "0123456789ABCDEF", 16);
	else
		ft_memcpy(symbols, "0123456789abcdef", 16);
	if (letter == P)
	{
		ft_putstr_pr("0x");
		len_res += 2;
	}
	while (j >= 1)
	{
		if (n / j <= base)
			len_res += ft_putchar_pr(symbols[n / j]);
		n %= j;
		j /= base;
	}
	return (len_res);
}

int		lenght_uns(unsigned long n, unsigned long base, unsigned long len,\
unsigned long *j)
{
	while (n / (*j) >= base)
	{
		len++;
		(*j) *= base;
	}
	len++;
	return (len);
}

int		ft_itoa_unslong(unsigned long n, unsigned long base, int letter,\
t_struct flags)
{
	unsigned int	len;
	unsigned long	nb;
	unsigned long	j;
	int				len_res;

	j = 1;
	len_res = 0;
	nb = n;
	len = lenght_uns(nb, base, 0, &j);
	len_res += if_flags_ito(flags, len, base, letter);
	if (flags.precision != 0)
		len_res += fill_uns(base, nb, j, letter);
	for_minus(flags, len, base, &len_res);
	return (len_res);
}
