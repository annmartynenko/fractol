/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:01:29 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/19 18:01:31 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	number(char format, va_list ap, t_struct flags, int *len_res)
{
	if ((format == 'd' || format == 'i'))
		ft_putnumber(va_arg(ap, int), flags, len_res);
	else if (format == 'D')
		ft_putlnbr(va_arg(ap, long int), flags, len_res);
	else if (format == 'U')
		ft_putunslnbr(va_arg(ap, unsigned long int), flags, len_res);
	else if (format == 'O')
		(*len_res) += ft_itoa_unslong(va_arg(ap, unsigned long int), 8, UP,\
		flags);
	else if (format == 'p')
		(*len_res) += ft_itoa_base_pr(va_arg(ap, long long), 16, P, flags);
}

int		convert(char format, va_list ap, t_struct flags)
{
	int len_res;

	len_res = 0;
	if (format == 'o')
		len_res += ft_itoa_base_int(va_arg(ap, int), 8, LOW, flags);
	else if (format == 'u')
		ft_putunslnbr((unsigned int)va_arg(ap, intmax_t), flags, &len_res);
	else if (format == 'x')
		len_res += ft_itoa_base_int(va_arg(ap, int), 16, LOW, flags);
	else if (format == 'X')
		len_res += ft_itoa_base_int(va_arg(ap, int), 16, UP, flags);
	return (len_res);
}

void	word(char format, va_list ap, t_struct flags, int *len_res)
{
	if (format == 's')
		ft_putstring(va_arg(ap, char*), flags, len_res);
	else if (format == 'S')
		uni_str(va_arg(ap, wchar_t*), flags, len_res);
	else if (format == 'c')
	{
		if (flags.width > 1 && !flags.minus && !flags.nul)
			n_time((flags.width - 1), len_res, ' ');
		else if (flags.width > 1 && !flags.minus && flags.nul)
			n_time((flags.width - 1), len_res, '0');
		(*len_res) += ft_putchar_pr((char)va_arg(ap, int));
		if (flags.width > 1 && flags.minus)
			n_time((flags.width - 1), len_res, ' ');
	}
	else if (format == 'C')
		unicode(va_arg(ap, wchar_t), flags, UNCO, len_res);
}
