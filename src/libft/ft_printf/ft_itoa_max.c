/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:47:56 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/12 13:47:57 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		fill_max(uintmax_t base, uintmax_t n, uintmax_t j, int letter)
{
	char	symbols[16];
	int		len_res;

	len_res = 0;
	if (letter == 1)
		ft_memcpy(symbols, "0123456789ABCDEF", 16);
	else if (letter == 0)
		ft_memcpy(symbols, "0123456789abcdef", 16);
	else if (letter == P)
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

int		lenght_max(uintmax_t n, uintmax_t base, unsigned long len,\
uintmax_t *j)
{
	while (n / (*j) >= base)
	{
		len++;
		(*j) *= base;
	}
	len++;
	return (len);
}

int		ft_itoa_max(uintmax_t n, uintmax_t base, int letter, t_struct flags)
{
	unsigned int		len;
	uintmax_t			nb;
	uintmax_t			j;
	int					len_res;

	j = 1;
	len_res = 0;
	nb = n;
	len = lenght_max(nb, base, 0, &j);
	len_res += if_flags_ito(flags, len, base, letter);
	len_res += fill_max(base, nb, j, letter);
	for_minus(flags, len, base, &len_res);
	return (len_res);
}
