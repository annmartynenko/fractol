/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:05:46 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/08 17:05:47 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		fill_int(unsigned int base, unsigned int n, unsigned int j, int letter)
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

int		lenght(unsigned int n, unsigned int base, unsigned int len,\
unsigned int *j)
{
	while (n / (*j) >= base)
	{
		len++;
		(*j) *= base;
	}
	len++;
	return (len);
}

int		ft_itoa_base_int(unsigned int n, unsigned int base, int letter,\
t_struct flags)
{
	unsigned int	len;
	unsigned int	nb;
	unsigned int	j;
	int				len_res;

	j = 1;
	len_res = 0;
	nb = n;
	if (n == 0)
		letter = -1;
	len = lenght(nb, base, 0, &j);
	len_res += if_flags_ito(flags, len, base, letter);
	if (n != 0 && flags.precision == 0)
		flags.precision = -1;
	if (flags.precision != 0)
		len_res += fill_int(base, nb, j, letter);
	for_minus(flags, len, base, &len_res);
	return (len_res);
}
