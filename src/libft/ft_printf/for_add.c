/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:37:00 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/22 14:37:01 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	for_h(char format, va_list ap, t_struct flags, int *len_res)
{
	if (format == 'x')
		*len_res += ft_itoa_unslong((unsigned short)va_arg(ap, int), 16, LOW,\
		flags);
	else if (format == 'X')
		*len_res += ft_itoa_unslong((unsigned short)va_arg(ap, int), 16, UP,\
		flags);
	else if (format == 'U')
		ft_putunslnbr(va_arg(ap, unsigned long), flags, len_res);
	else if (format == 'o')
		*len_res += ft_itoa_unslong((unsigned short)va_arg(ap, int), 8, LOW,\
		flags);
	else if (format == 'u')
		ft_putunslnbr((unsigned short)va_arg(ap, int), flags, len_res);
	else if (format == 'O')
		(*len_res) += ft_itoa_base_pr(va_arg(ap, unsigned long int), 8, UP, \
		flags);
	else if (format == 'D')
		ft_putlnbr(va_arg(ap, long int), flags, len_res);
}

void	for_l(char format, va_list ap, t_struct flags, int *len_res)
{
	if (format == 'x')
		*len_res += ft_itoa_unslong(va_arg(ap, unsigned long), 16, LOW, flags);
	else if (format == 'X')
		*len_res += ft_itoa_unslong(va_arg(ap, unsigned long), 16, UP, flags);
	else if (format == 'o')
		*len_res += ft_itoa_unslong(va_arg(ap, unsigned long), 8, LOW, flags);
	else if (format == 'u')
		ft_putunslnbr(va_arg(ap, unsigned long), flags, len_res);
	else if (format == 's')
		uni_str((wchar_t*)va_arg(ap, char*), flags, len_res);
	else if (format == 'c')
		unicode((wchar_t)va_arg(ap, int), flags, UNCO, len_res);
	else if (format == 'O')
		(*len_res) += ft_itoa_base_pr(va_arg(ap, unsigned long int), 8, UP,\
		flags);
	else if (format == 'U')
		ft_putunslnbr(va_arg(ap, unsigned long int), flags, len_res);
	else if (format == 'D')
		ft_putlnbr(va_arg(ap, long int), flags, len_res);
	else if (format == 'p')
		(*len_res) += ft_itoa_base_pr(va_arg(ap, long long), 16, P, flags);
}

void	for_ll(char format, va_list ap, t_struct flags, int *len_res)
{
	if (format == 'd' || format == 'i')
		ft_putnumber(va_arg(ap, long long), flags, len_res);
	else if (format == 'x')
		*len_res += ft_itoa_max(va_arg(ap, unsigned long long), 16, LOW, flags);
	else if (format == 'X')
		*len_res += ft_itoa_max(va_arg(ap, unsigned long long), 16, UP, flags);
	else if (format == 'o')
		*len_res += ft_itoa_unslong((unsigned long long)va_arg(ap, uintmax_t),\
		8, LOW, flags);
	else if (format == 'u')
		ft_putunslnbr((unsigned long long)va_arg(ap, uintmax_t), flags,\
		len_res);
	else if (format == 'O')
		(*len_res) += ft_itoa_base_pr(va_arg(ap, unsigned long int), 8, UP,\
		flags);
	else if (format == 'U')
		ft_putunslnbr(va_arg(ap, unsigned long int), flags, len_res);
	else if (format == 'D')
		ft_putlnbr(va_arg(ap, long int), flags, len_res);
}

void	for_hh(char format, va_list ap, t_struct flags, int *len_res)
{
	if (format == 'd' || format == 'i')
		ft_putschar((signed char)va_arg(ap, int), flags, len_res);
	else if (format == 'x')
		*len_res += ft_itoa_max((unsigned char)va_arg(ap, int), 16, LOW, flags);
	else if (format == 'X')
		*len_res += ft_itoa_max((unsigned char)va_arg(ap, int), 16, UP, flags);
	else if (format == 'o')
		*len_res += ft_itoa_unslong((unsigned char)va_arg(ap, int), 8,\
		LOW, flags);
	else if (format == 'u')
		ft_putunslnbr((unsigned char)va_arg(ap, int), flags, len_res);
	else if (format == 'O')
		(*len_res) += ft_itoa_base_pr((unsigned short)va_arg(ap, int), 8,\
		UP, flags);
	else if (format == 'U')
		ft_putunslnbr((unsigned short)va_arg(ap, int), flags, len_res);
	else if (format == 'D')
		ft_putlnbr((unsigned short)va_arg(ap, int), flags, len_res);
	else if (format == 'C')
		unicode(va_arg(ap, wchar_t), flags, UNCO, len_res);
	else if (format == 'S')
		uni_str((wchar_t*)va_arg(ap, char*), flags, len_res);
}
