/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:41:47 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/02 16:41:48 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		specx2(char *format, int *i, va_list ap, t_struct flags)
{
	int len_res;

	len_res = 0;
	(*i) += 1;
	if (format[(*i) - 2] == 'l' && format[(*i) - 1] == 'l')
		for_ll(format[(*i)], ap, flags, &len_res);
	else if (format[(*i) - 2] == 'h' && format[(*i) - 1] == 'h')
		for_hh(format[*i], ap, flags, &len_res);
	else
		(*i) -= 1;
	return (len_res);
}

int		sp_z2(char *format, int *i, va_list ap, t_struct flags)
{
	int len_res;

	len_res = 0;
	if (format[(*i)] == 'x')
		len_res += ft_itoa_max(va_arg(ap, size_t), 16, LOW, flags);
	else if (format[(*i)] == 'X')
		len_res += ft_itoa_max(va_arg(ap, size_t), 16, UP, flags);
	else if (format[(*i)] == 'o')
		len_res += ft_itoa_unslong(va_arg(ap, size_t), 8, LOW, flags);
	else if (format[(*i)] == 'u')
		ft_putunslnbr(va_arg(ap, size_t), flags, &len_res);
	else if (format[(*i)] == 'O')
		len_res += ft_itoa_base_pr(va_arg(ap, size_t), 8, UP, flags);
	else if (format[(*i)] == 'U')
		ft_putunslnbr(va_arg(ap, size_t), flags, &len_res);
	else if (format[(*i)] == 'D')
		ft_putlnbr(va_arg(ap, size_t), flags, &len_res);
	return (len_res);
}

int		specifier_z(char *format, int *i, va_list ap, t_struct flags)
{
	int				len_res;

	(*i)++;
	len_res = 0;
	if (format[(*i) - 1] == 'z')
	{
		if (format[(*i)] == 'd' || format[(*i)] == 'i')
			ft_putnumber(va_arg(ap, size_t), flags, &len_res);
		else if (format[(*i)])
			len_res += sp_z2(format, i, ap, flags);
	}
	else
		(*i)--;
	return (len_res);
}

int		specifier_lh(char *format, int *i, va_list ap, t_struct flags)
{
	int	len_res;

	len_res = 0;
	(*i)++;
	if (format[(*i) - 1] == 'l')
	{
		if (format[(*i)] == 'd' || format[(*i)] == 'i')
			ft_putnumber(va_arg(ap, long), flags, &len_res);
		else if (format[(*i)] != 'l')
			for_l(format[(*i)], ap, flags, &len_res);
	}
	else if (format[(*i) - 1] == 'h')
	{
		if (format[(*i)] == 'd' || format[(*i)] == 'i')
			ft_putnumber((short)va_arg(ap, int), flags, &len_res);
		else if (format[(*i) + 1] != 'h')
			for_h(format[(*i)], ap, flags, &len_res);
	}
	else
		(*i)--;
	return (len_res);
}

int		specifier(char *format, int *i, va_list ap, t_struct flags)
{
	int len_res;

	len_res = 0;
	len_res += specifier_lh(format, i, ap, flags);
	len_res += specx2(format, i, ap, flags);
	len_res += specifier_z(format, i, ap, flags);
	len_res += specifier_j(format, i, ap, flags);
	return (len_res);
}
