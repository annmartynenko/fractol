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

void	start_m(t_calc *a)
{
//	map->zoom = 1;
//	map->moveX = -0.5;
//	map->moveY = 0;
	a->max_iter = 300;
	a->newRe = a->newIm = a->oldIm = a->oldRe = 0;
	a->pr = 0;
	a->pi = 0;
}

void	mandelbrot(t_mass *map, int x, int y)
{
	int i;
	t_calc a;

	start_m(&a);
	i = -1;
	a.pr = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight) + map->moveX;
	a.pi = (y - map->height / 2) / (0.5 * map->zoom * map->height) + map->moveY;
	a.newRe = a.newIm = a.oldIm = a.oldRe = 0;
	while (++i < a.max_iter)
	{
		a.oldRe = a.newRe;
		a.oldIm = a.newIm;
		a.newRe = a.oldRe * a.oldRe - a.oldIm * a.oldIm + a.pr;
		a.newIm = 2 * a.oldRe * a.oldIm + a.pi;
		if (a.newRe * a.newRe + a.newIm * a.newIm > 4)
			break;
	}
	if (i == a.max_iter)
		map->image[x + (y * map->weight)] = 0xffe1ff;
	else
		map->image[x + (y * map->weight)] = 0xffe1ff * i;

}

void	start_j(t_calc *a, t_mass *map)
{
	map->zoom = 1;
	map->moveX = 0;
	map->moveY = 0;
	a->max_iter = 300;
	a->newIm = a->newRe = a->oldIm = a->oldRe = 0;
}

void	julia(t_mass *map, int x, int y)
{
	int i;
	t_calc a;

	start_j(&a, map);
	i = -1;
	a.newRe = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight) + map->moveX;
	a.newIm = (y - map->height / 2) / (0.5 * map->zoom * map->height) + map->moveY;
	while (++i < a.max_iter)
	{
		a.oldRe = a.newRe;
		a.oldIm = a.newIm;
		a.newRe = a.oldRe * a.oldRe - a.oldIm * a.oldIm + map->cRe;
		a.newIm = 2 * a.oldRe * a.oldIm + map->cIm;
		if (a.newRe * a.newRe + a.newIm * a.newIm > 4)
			break;
	}
	if (i == a.max_iter)
		map->image[x + (y * map->weight)] = 0xffe1ff;
	else
		map->image[x + (y * map->weight)] = 0xffe1ff * i;

}

void	start_h(t_calc *a, t_mass *map)
{
//	map->zoom = 1;
//	map->moveX = -0.5;
//	map->moveY = 0;
	map->cIm = -0.1;
	map->cRe = 0.258;
	a->max_iter = 300;
	a->newRe = 0;
	a->newIm = 0;
	a->oldIm = a->oldRe = 0;
	a->pr = 0;
	a->pi = 0;
}

void	heart(t_mass *map, int x, int y)
{
	int i;
	t_calc	a;

	start_h(&a, map);
	i = -1;
	while (++i < a.max_iter)
	{
		a.newRe = a.oldRe * a.oldRe - a.oldIm * a.oldIm + map->cRe;
		a.newIm = 2 * fabs(a.oldRe) * a.oldIm + map->cIm;
		a.oldRe = a.newRe;
		if (a.newRe * a.newRe + a.newIm * a.newIm > 4)
			break;
	}
	if (i == a.max_iter)
		map->image[x + (y * map->weight)] = 0xffe1ff;
	else
		map->image[x + (y * map->weight)] = 0xffffff * i;
}
