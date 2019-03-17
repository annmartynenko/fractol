/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:34:37 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/17 17:34:38 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	start_c(t_calc *a, t_mass *map, int x, int y)
{
	map->c_im = 0;
	map->c_re = 0;
	a->new_re = 0;
	a->new_im = 0;
	a->old_im = 0;
	a->old_re = 0;
	a->pr = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight)\
	+ map->move_x;
	a->pi = (y - map->height / 2) / (0.5 * map->zoom * map->height)\
	+ map->move_y;
}

void	celtic(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_c(&a, map, x, y);
	i = -1;
	while (++i < map->max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_re = fabs(a.old_re * a.old_re - a.old_im * a.old_im) + a.pr;
		a.new_im = 2 * a.old_re * a.old_im + a.pi;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	get_color(x, y, map, i);
}

void	start_b(t_calc *a, t_mass *map, int x, int y)
{
	a->new_im = 0;
	a->new_re = 0;
	a->old_im = 0;
	a->old_re = 0;
	a->pr = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight)\
	+ map->move_x;
	a->pi = (y - map->height / 2) / (0.5 * map->zoom * map->height)\
	+ map->move_y;
}

void	buffalo(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_b(&a, map, x, y);
	i = -1;
	while (++i < map->max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_im = 2 * fabs(a.old_re * a.old_im) + a.pi;
		a.new_re = fabs(a.old_re * a.old_re - a.old_im * a.old_im) + a.pr;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	get_color(x, y, map, i);
}
