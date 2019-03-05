/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:11:38 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/10 14:29:40 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	flags_string(t_struct flags, int *len_res, int len)
{
	if (flags.width > len && !flags.minus && flags.precision == -1 &&\
		flags.nul)
		n_time((flags.width - len), len_res, '0');
	else if (flags.width > len && !flags.minus && flags.precision == -1)
		n_time((flags.width - len), len_res, ' ');
	else if (flags.precision < flags.width && flags.precision > len &&\
		flags.precision != -1 && !flags.minus)
		n_time((flags.width - len), len_res, ' ');
	else if (flags.precision < flags.width && flags.precision < len &&\
		flags.precision != -1 && !flags.minus)
		n_time((flags.width - flags.precision), len_res, ' ');
	else if (flags.precision > flags.width && flags.width > len &&\
		flags.precision != -1 && !flags.minus)
		n_time((flags.width - len), len_res, ' ');
	else if (flags.width > flags.precision && !flags.minus &&\
		flags.precision != -1)
	{
		if (len == 0)
			n_time((flags.width), len_res, ' ');
		else
			n_time((flags.width - flags.precision), len_res, ' ');
	}
}

void	flags_string_after(t_struct flags, int *len_res, int len)
{
	if (flags.width > len && flags.minus && flags.precision == -1)
		n_time((flags.width - len), len_res, ' ');
	else if (flags.width > flags.precision && flags.minus)
	{
		if (flags.precision <= len && flags.precision != -1)
			n_time((flags.width - flags.precision), len_res, ' ');
		else if (flags.precision > len && flags.precision != -1)
			n_time(flags.width - len, len_res, ' ');
	}
}

void	ft_putstring(char const *s, t_struct flags, int *len_res)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(s);
	if (s != NULL)
	{
		flags_string(flags, len_res, len);
		while (s[i] != '\0')
		{
			if (flags.precision != -1 && i == flags.precision)
				break ;
			(*len_res) += ft_putchar_pr(s[i]);
			i++;
		}
		flags_string_after(flags, len_res, len);
	}
	else if (s == 0 && flags.width)
		n_time(flags.width, len_res, '0');
	else if (!flags.width)
		*len_res += ft_putstr_pr("(null)");
}

void	ft_putwchr(wchar_t *s, t_struct flags, int *len_res)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (flags.precision != -1 && i == flags.precision)
				break ;
			(*len_res) += 1;
			ft_putwchr(s, flags, len_res);
			i++;
		}
	}
	else
		*len_res += ft_putstr_pr("(null)");
}
