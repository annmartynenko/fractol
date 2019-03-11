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

void	start_m(t_mass *map)
{
//	map->zoom = 1;
//	map->moveX = -0.5;
//	map->moveY = 0;
	map->a.max_iter = 300;
	map->a.newRe = map->a.newIm = map->a.oldIm = map->a.oldRe = 0;
	map->a.pr = 0;
	map->a.pi = 0;
}

void	mandelbrot(t_mass *map, int x, int y)
{
//	int y;
//	int x;
	int i;

//	y = -1;
	start_m(map);
//	while (++y < map->height)
//	{
//		x = -1;
//		while (++x < map->weight)
//		{
			i = -1;
			map->a.pr = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight) + map->moveX;
			map->a.pi = (y - map->height / 2) / (0.5 * map->zoom * map->height) + map->moveY;
			map->a.newRe = map->a.newIm = map->a.oldIm = map->a.oldRe = 0;
			while (++i < map->a.max_iter)
			{
				map->a.oldRe = map->a.newRe;
				map->a.oldIm = map->a.newIm;
				map->a.newRe = map->a.oldRe * map->a.oldRe - map->a.oldIm * map->a.oldIm + map->a.pr;
				map->a.newIm = 2 * map->a.oldRe * map->a.oldIm + map->a.pi;
				if (map->a.newRe * map->a.newRe + map->a.newIm * map->a.newIm > 4)
					break;
			}
			if (i == map->a.max_iter)
				map->image[x + (y * map->weight)] = 0xffe1ff;
			else
				map->image[x + (y * map->weight)] = 0xffe1ff * i;
//		}
//	}
}

void	start_j(t_mass *map)
{
	map->zoom = 1;
	map->moveX = 0;
	map->moveY = 0;
	map->a.max_iter = 300;
	map->a.newIm = map->a.newRe = map->a.oldIm = map->a.oldRe = 0;
}

void	julia(t_mass *map)
{
	int y;
	int x;
	int i;

	y = -1;
	start_j(map);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->weight)
		{
			i = -1;
			map->a.newRe = 1.5 * (x - map->weight / 2) / (0.5 * map->zoom * map->weight) + map->moveX;
			map->a.newIm = (y - map->height / 2) / (0.5 * map->zoom * map->height) + map->moveY;
			while (++i < map->a.max_iter)
			{
				map->a.oldRe = map->a.newRe;
				map->a.oldIm = map->a.newIm;
				map->a.newRe = map->a.oldRe * map->a.oldRe - map->a.oldIm * map->a.oldIm + map->cRe;
				map->a.newIm = 2 * map->a.oldRe * map->a.oldIm + map->cIm;
				if (map->a.newRe * map->a.newRe + map->a.newIm * map->a.newIm > 4)
					break;
			}
			if (i == map->a.max_iter)
				map->image[x + (y * map->weight)] = 0xffe1ff;
			else
				map->image[x + (y * map->weight)] = 0xffe1ff * i;
		}
	}
}
