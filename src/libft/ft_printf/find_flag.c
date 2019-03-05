/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:00:36 by amartyne          #+#    #+#             */
/*   Updated: 2018/08/28 15:01:25 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int			int_len(int nbr)
{
	int i;

	if (nbr >= 0)
		i = 1;
	else
		i = 2;
	while (nbr /= 10)
		i++;
	return (i);
}

t_struct	field(char *str, t_struct flags, int *i)
{
	if (ft_isdigit(str[(*i)]))
	{
		if (flags.precision == '.')
		{
			flags.precision = ft_atoi(str + *i);
			*i = *i + int_len(flags.precision);
		}
		else
		{
			flags.width = ft_atoi(str + *i);
			*i = *i + int_len(flags.width);
		}
	}
	return (flags);
}

void		next_fl(char *str, int *i, t_struct *flags)
{
	if (str[(*i)] == '-')
	{
		(*flags).minus = '-';
		(*i)++;
	}
	if (str[(*i)] == '+')
	{
		(*flags).plus = '+';
		(*i)++;
	}
	if (str[(*i)] == ' ')
	{
		(*flags).space = ' ';
		(*i)++;
	}
	if (str[(*i)] == '#')
	{
		(*flags).hash = '#';
		(*i)++;
	}
	if (str[(*i)] == (char)48)
	{
		(*flags).nul = '1';
		(*i)++;
	}
}

t_struct	create_struct(void)
{
	t_struct flags;

	flags.hash = 0;
	flags.space = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.nul = 0;
	flags.precision = -1;
	flags.plus = 0;
	flags.sp = 0;
	return (flags);
}

t_struct	find_flag(char *str, int *i, va_list ap)
{
	t_struct flags;

	flags = create_struct();
	while (valid(str[(*i)]) == 2)
	{
		next_fl(str, i, &flags);
		if (str[(*i)] == '*')
		{
			flags.width = va_arg(ap, int);
			(*i)++;
		}
		flags = field(str, flags, i);
		if (str[(*i)] == '.')
		{
			flags.precision = '.';
			(*i)++;
		}
		flags = field(str, flags, i);
	}
	if (flags.precision == '.')
		flags.precision = 0;
	return (flags);
}
