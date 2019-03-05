/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:06:59 by amartyne          #+#    #+#             */
/*   Updated: 2018/09/09 15:07:02 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	for_minus(t_struct flags, int len, int base, int *len_res)
{
	int dot;

	dot = 0;
	if (flags.hash && base == 16)
		dot = 2;
	else if (flags.hash && base == 8)
		dot = 1;
	if (flags.minus && flags.width > len)
	{
		if (flags.width > flags.precision && flags.precision != -1)
			n_time((flags.width - flags.precision - dot), len_res, ' ');
		else if (flags.width && flags.precision == -1)
			n_time((flags.width - len - dot), len_res, ' ');
	}
}

int		print_space(t_struct flags, int len, int base, int letter)
{
	int len_res;

	len_res = 0;
	if (flags.hash && base == 8)
	{
		if (!flags.minus)
			n_time((flags.width - len - 1), &len_res, ' ');
		if (letter != -1)
			len_res += ft_putchar_pr('0');
	}
	else if ((flags.hash && base == 16) || letter == P)
	{
		if (!flags.minus)
			n_time((flags.width - len - 2), &len_res, ' ');
		if (letter == LOW)
			len_res += ft_putstr_pr("0x");
		else if (letter == UP)
			len_res += ft_putstr_pr("0X");
		else if (letter == P)
			len_res += ft_putstr_pr("0x");
	}
	else
		n_time((flags.width - len), &len_res, ' ');
	return (len_res);
}

int		print_nul(t_struct flags, int len, int base, int letter)
{
	int len_res;

	len_res = 0;
	if (flags.hash && base == 8)
	{
		len_res += ft_putchar_pr('0');
		n_time((flags.width - len - 1), &len_res, '0');
	}
	else if (flags.hash && base == 16)
	{
		if (letter == LOW)
			len_res += ft_putstr_pr("0x");
		else if (letter == UP)
			len_res += ft_putstr_pr("0X");
		if (!flags.minus)
			n_time((flags.width - len - 2), &len_res, '0');
	}
	else if (flags.precision != -1)
		n_time((flags.precision - len), &len_res, '0');
	else
		n_time((flags.width - len), &len_res, '0');
	return (len_res);
}

int		print_nul_pr(t_struct flags, int len, int base, int letter)
{
	int len_res;

	len_res = 0;
	if (flags.hash && base == 8)
	{
		len_res += ft_putchar_pr('0');
		len++;
		n_time((flags.precision - len), &len_res, '0');
	}
	else if (flags.hash && base == 16)
	{
		if (letter == LOW)
			len_res += ft_putstr_pr("0x");
		else if (letter == UP)
			len_res += ft_putstr_pr("0X");
		n_time((flags.precision - len), &len_res, '0');
	}
	else
		n_time((flags.precision - len), &len_res, '0');
	return (len_res);
}
