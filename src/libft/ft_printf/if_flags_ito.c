/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_flags_ito.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:04:11 by amartyne          #+#    #+#             */
/*   Updated: 2018/11/10 18:04:12 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		flags_ito2(t_struct flags, int len, int base, int letter)
{
	int len_res;

	len_res = 0;
	if (flags.width > len && flags.nul && !flags.minus)
		len_res += print_nul(flags, len, base, letter);
	else if (flags.width > len && !flags.minus && !flags.nul &&\
	flags.precision == -1)
		len_res += print_space(flags, len, base, letter);
	else if (flags.precision != -1 && flags.precision <= flags.width &&\
	flags.hash && flags.width)
		len_res += print_nul_pr(flags, len, base, letter);
	else if (flags.precision != -1 && flags.precision > flags.width &&\
	flags.hash)
		len_res += print_nul_pr(flags, len, base, letter);
	else if (flags.hash && flags.precision == -1)
		len_res += print_space(flags, len, base, letter);
	else if (flags.precision != -1)
		len_res += print_nul(flags, len, base, letter);
	return (len_res);
}

int		if_flags_ito(t_struct flags, int len, int base, int letter)
{
	int len_res;

	len_res = 0;
	if (letter == P)
		len_res += for_p(flags, len);
	else if (flags.width > len && flags.precision != -1 && \
	flags.width > flags.precision && !flags.hash && flags.precision >= len &&\
	!flags.minus)
	{
		n_time((flags.width - flags.precision), &len_res, ' ');
		n_time((flags.precision - len), &len_res, '0');
	}
	else if (flags.width > len && flags.precision != -1 &&\
	flags.width > flags.precision && !flags.hash && !flags.minus && letter != P)
	{
		if (flags.precision == 0)
			len = 0;
		n_time((flags.width - len), &len_res, ' ');
	}
	else if (flags.width > len && flags.width <= flags.precision &&\
	!flags.hash)
		n_time((flags.precision - len), &len_res, '0');
	else
		len_res += flags_ito2(flags, len, base, letter);
	return (len_res);
}
