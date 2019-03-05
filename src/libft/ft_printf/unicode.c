/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:50:51 by amartyne          #+#    #+#             */
/*   Updated: 2018/08/24 11:50:54 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <locale.h>

int		count_bin(unsigned int numb)
{
	int len;

	len = 0;
	while (numb > 0)
	{
		numb = numb >> 1;
		len++;
	}
	return (len);
}

int		two_bin(unsigned int numb)
{
	unsigned char part1;
	unsigned char part2;
	unsigned char res;

	part1 = ((numb >> 6) << 27) >> 27;
	part2 = ((numb << 26) >> 26);
	res = (192 | part1);
	write(1, &res, 1);
	res = (128 | part2);
	write(1, &res, 1);
	return (2);
}

int		three_bin(unsigned int numb)
{
	unsigned char part1;
	unsigned char part2;
	unsigned char part3;
	unsigned char res;

	part1 = ((numb >> 12) << 28) >> 28;
	part2 = ((numb >> 6) << 26) >> 26;
	part3 = (numb << 26) >> 26;
	res = (224 | part1);
	write(1, &res, 1);
	res = (128 | part2);
	write(1, &res, 1);
	res = (128 | part3);
	write(1, &res, 1);
	return (3);
}

int		four_bin(unsigned int numb)
{
	unsigned char part1;
	unsigned char part2;
	unsigned char part3;
	unsigned char part4;
	unsigned char res;

	part1 = ((numb >> 18) << 29) >> 29;
	part2 = ((numb >> 12) << 26) >> 26;
	part3 = ((numb >> 6) << 26) >> 26;
	part4 = (numb << 26) >> 26;
	res = (240 | part1);
	write(1, &res, 1);
	res = (128 | part2);
	write(1, &res, 1);
	res = (128 | part3);
	write(1, &res, 1);
	res = (128 | part4);
	write(1, &res, 1);
	return (4);
}

void	unicode(wchar_t numb, t_struct flags, int mark, int *len_res)
{
	int				size;
	int				len;
	unsigned int	value;

	value = (unsigned int)numb;
	size = count_bin(value);
	len = len_unco(size);
	if (size == 0)
		size = 1;
	if (flags.width > len && !flags.minus && !flags.nul && mark == UNCO)
		n_time((flags.width - len), len_res, ' ');
	if (size <= 7 || MB_CUR_MAX == 1)
		*len_res += ft_putchar_pr(value);
	else if (size <= 11)
		*len_res += two_bin(value);
	else if (size <= 16)
		*len_res += three_bin(value);
	else
		*len_res += four_bin(value);
	if (flags.width > len && flags.minus && !flags.nul && mark == UNCO)
		n_time((flags.width - len), len_res, ' ');
}
