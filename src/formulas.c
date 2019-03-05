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

t_calc	start_m()
{
	t_calc a;

	a.zoom = 1;
	a.moveX = -0.5;
	a.moveY = 0;
	a.max_iter = 300;
	a.newRe = a.newIm = a.oldIm = a.oldRe = 0;
	a.pr = 0;
	a.pi = 0;
	return (a);
}

void	mandelbrot(t_mass *map)
{
	t_calc a;
	int y;
	int x;
	int i;

	y = -1;
	a = start_m();
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->weight)
		{
			i = -1;
			a.pr = 1.5 * (x - map->weight / 2) / (0.5 * a.zoom * map->weight) + a.moveX;
			a.pi = (y - map->height / 2) / (0.5 * a.zoom * map->height) + a.moveY;
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
	}
}

t_calc	start_j()
{
	t_calc a;

	a.zoom = 1;
	a.moveX = 0;
	a.moveY = 0;
	a.max_iter = 300;
	a.pr = -0.7;
	a.pi = 0.27015;
	a.newIm = a.newRe = a.oldIm = a.oldRe = 0;
	return (a);
}

void	julia(t_mass *map)
{
	t_calc a;
	int y;
	int x;
	int i;

	y = -1;
	a = start_j();
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->weight)
		{
			i = -1;
			a.newRe = 1.5 * (x - map->weight / 2) / (0.5 * a.zoom * map->weight) + a.moveX;
			a.newIm = (y - map->height / 2) / (0.5 * a.zoom * map->height) + a.moveY;
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
	}
}
