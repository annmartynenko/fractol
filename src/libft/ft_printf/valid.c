/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:30:18 by amartyne          #+#    #+#             */
/*   Updated: 2018/10/07 19:30:25 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		valid(char format)
{
	if ((format == 'd') || (format == 'i') || (format == 'O') ||\
	(format == 'o') || (format == 'x') || (format == 'X') || (format == 'u') ||\
	(format == 'U') || (format == 'S') || (format == 'c') || (format == 'C') ||\
	(format == 'p') || (format == 's') || (format == 'l') || (format == 'j') ||\
	(format == 'z') || (format == 'h') || (format == 'D'))
		return (1);
	if ((format == ' ') || (format == '.') || (format == '+') ||\
	(format == '-') || (format == '#') || ft_isdigit(format))
		return (2);
	return (0);
}
