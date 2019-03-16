/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:03:15 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/16 16:03:17 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	start_s(t_calc *a, t_mass *map, int x, int y)
{
	a->max_iter = MAX_ITER;
	a->new_re = 0;
	a->new_im = 0;
	a->old_im = 0;
	a->old_re = 0;
	a->pr = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight)\
	+ map->move_x;
	a->pi = (y - map->height / 2) / (0.5 * map->zoom * map->height)\
	+ map->move_y;
}

void	ship(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_s(&a, map, x, y);
	i = -1;
	while (++i < a.max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_re = a.old_re * a.old_re - a.old_im * a.old_im + a.pr;
		a.new_im = 2 * fabs(a.old_re * a.old_im) + a.pi;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	map->z = (a.new_re * a.new_re + a.new_im * a.new_im);
	get_color(x, y, map, i);
}

void	start_f(t_calc *a, t_mass *map, int x, int y)
{
	a->max_iter = MAX_ITER;
	a->new_im = 0;
	a->new_re = 0;
	a->old_im = 0;
	a->old_re = 0;
	a->new_re = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight)\
	+ map->move_x;
	a->new_im = (y - map->height / 2) / (0.5 * map->zoom * map->height)\
	+ map->move_y;
}

void	flower(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_f(&a, map, x, y);
	i = -1;
	while (++i < a.max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_re = log(a.old_re * a.old_re) - log(a.old_im * a.old_im)\
		+ map->c_re;
		a.new_im = 2 * (a.old_re * a.old_im) + map->c_im;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	map->z = a.new_re * a.new_re + a.new_im * a.new_im;
	get_color(x, y, map, i);
}
