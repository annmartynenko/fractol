/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:56:27 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/04 18:56:33 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	start_m(t_calc *a, t_mass *map, int x, int y)
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

void	mandelbrot(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_m(&a, map, x, y);
	i = -1;
	while (++i < map->max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_re = a.old_re * a.old_re - a.old_im * a.old_im + a.pr;
		a.new_im = 2 * a.old_re * a.old_im + a.pi;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	get_color(x, y, map, i);
}

void	start_j(t_calc *a, t_mass *map, int x, int y)
{
	a->new_im = 0;
	a->new_re = 0;
	a->old_im = 0;
	a->old_re = 0;
	a->pr = 0;
	a->pi = 0;
	a->new_re = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight)\
	+ map->move_x;
	a->new_im = (y - map->height / 2) / (0.5 * map->zoom * map->height)\
	+ map->move_y;
}

void	julia(t_mass *map, int x, int y)
{
	int		i;
	t_calc	a;

	start_j(&a, map, x, y);
	i = -1;
	while (++i < map->max_iter)
	{
		a.old_re = a.new_re;
		a.old_im = a.new_im;
		a.new_re = a.old_re * a.old_re - a.old_im * a.old_im + map->c_re;
		a.new_im = 2 * a.old_re * a.old_im + map->c_im;
		if (a.new_re * a.new_re + a.new_im * a.new_im > 4)
			break ;
	}
	get_color(x, y, map, i);
}
