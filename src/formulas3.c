/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 12:04:26 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/17 12:04:27 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	start_t(t_calc *a, t_mass *map, int x, int y)
{
	a->new_re = 0;
	a->new_im = 0;
	a->old_im = 0;
	a->old_re = 0;
	a->pr = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight)\
	+ map->move_x;
	a->pi = (y - map->height / 2) / (0.5 * map->zoom * map->height)\
	+ map->move_y;
}

void	tricorn(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_t(&a, map, x, y);
	i = -1;
	while (++i < map->max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_re = a.old_re * a.old_re - a.old_im * a.old_im + a.pr;
		a.new_im = -2 * a.old_re * a.old_im + a.pi;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	get_color(x, y, map, i);
}

void	start_h(t_calc *a, t_mass *map, int x, int y)
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

void	heart(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_h(&a, map, x, y);
	i = -1;
	while (++i < map->max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_im = 2 * fabs(a.old_re) * a.new_im + a.pi;
		a.new_re = a.old_re * a.old_re - a.old_im * a.old_im + a.pr;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	get_color(x, y, map, i);
}
