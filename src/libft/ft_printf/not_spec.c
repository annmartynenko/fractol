/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:46:46 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/07 20:46:47 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	not_spec(t_struct flags, int *len_res)
{
	if (flags.width && !flags.minus && !flags.nul)
		n_time((flags.width - 1), len_res, ' ');
	else if (flags.width && flags.nul && !flags.minus)
		n_time((flags.width - 1), len_res, '0');
}

int		sp_j2(char *format, int *i, va_list ap, t_struct flags)
{
	int len_res;

	len_res = 0;
	if (format[(*i)] == 'x')
		len_res += ft_itoa_max(va_arg(ap, uintmax_t), 16, LOW, flags);
	else if (format[(*i)] == 'X')
		len_res += ft_itoa_max(va_arg(ap, uintmax_t), 16, UP, flags);
	else if (format[(*i)] == 'o')
		len_res += ft_itoa_unslong(\
				(unsigned long)va_arg(ap, uintmax_t), 8, LOW, flags);
	else if (format[(*i)] == 'u')
		ft_putunslnbr((unsigned long)va_arg(ap, uintmax_t), flags,\
				&len_res);
	else if (format[(*i)] == 'O')
		len_res += ft_itoa_base_pr(\
				(unsigned long)va_arg(ap, uintmax_t), 8, UP, flags);
	else if (format[(*i)] == 'U')
		ft_putunslnbr((unsigned long)va_arg(ap, uintmax_t),\
				flags, &len_res);
	else if (format[(*i)] == 'D')
		ft_putlnbr((unsigned long)va_arg(ap, uintmax_t),\
				flags, &len_res);
	return (len_res);
}

int		specifier_j(char *format, int *i, va_list ap, t_struct flags)
{
	int				len_res;

	(*i)++;
	len_res = 0;
	if (format[(*i) - 1] == 'j')
	{
		if (format[(*i)] == 'd' || format[(*i)] == 'i')
			ft_putnumber(va_arg(ap, intmax_t), flags, &len_res);
		else if (format[(*i)])
			len_res += sp_j2(format, i, ap, flags);
	}
	else
		(*i)--;
	return (len_res);
}
