/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:30:55 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/17 17:30:55 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	key_julia(int *julia)
{
	if ((*julia) == 1)
		(*julia) = 0;
	else
		(*julia) = 1;
}

void	set_start(t_mass *map)
{
	map->zoom = 0.7;
	map->move_y = 0;
	map->c_re = -0.7;
	map->c_im = 0.27015;
	map->red = 2;
	map->blue = 0;
	map->green = 10;
	map->julia = 1;
	map->max_iter = MAX_ITER;
	if (map->mark == 1 || map->mark == 3 || map->mark == 6)
		map->move_x = 0;
	else if (map->mark == 2 || map->mark == 4)
		map->move_x = -0.5;
	else if (map->mark == 8)
	{
		map->move_x = -0.5;
		map->move_y = -0.5;
	}
}

void	change_fractal(t_mass *map, int keycode)
{
	mlx_clear_window(map->mlx, map->wind);
	if (keycode == 83)
		map->mark = 1;
	else if (keycode == 84)
		map->mark = 2;
	else if (keycode == 85)
		map->mark = 3;
	else if (keycode == 86)
		map->mark = 4;
	else if (keycode == 87)
		map->mark = 5;
	else if (keycode == 88)
		map->mark = 6;
	else if (keycode == 89)
		map->mark = 7;
	else if (keycode == 91)
		map->mark = 8;
	set_start(map);
	mult(map);
}

void	change_zoom(t_mass *map, int keycode)
{
	if (keycode == 69)
	{
		map->zoom *= 1.1;
		map->max_iter += 5;
	}
	else if (keycode == 78)
	{
		map->zoom *= 0.9;
		map->max_iter -= 5;
	}
}
