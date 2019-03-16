/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:59:59 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/07 16:00:00 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	xy(t_mass *map, int keycode)
{
	double add;

	add = 0.1;
	if (map->zoom > 2 && map->zoom < 10)
		add = 0.01;
	else if (map->zoom >= 10 && map->zoom < 100)
		add = 0.001;
	else if (map->zoom >= 100 && map->zoom < 1000)
		add = 0.0001;
	else if (map->zoom >= 1000 && map->zoom < 10000)
		add = 0.00001;
	else if (map->zoom >= 10000)
		add = 0.000001;
	if (keycode == 124)
		map->move_x -= add;
	else if (keycode == 123)
		map->move_x += add;
	else if (keycode == 126)
		map->move_y += add;
	else if (keycode == 125)
		map->move_y -= add;
}

void	key_julia(int *julia)
{
	if ((*julia) == 1)
		(*julia) = 0;
	else
		(*julia) = 1;
}

int		key_press(int keycode, t_mass *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->wind);
		system("leaks fractol");
		exit(1);
	}
	mlx_clear_window(map->mlx, map->wind);
	if (keycode == 123 || keycode == 124 || keycode == 125 ||\
	keycode == 126)
		xy(map, keycode);
	else if (keycode == 69)
		map->zoom *= 1.1;
	else if (keycode == 78)
		map->zoom *= 0.9;
	else if (keycode == 15)
		map->red += 1;
	else if (keycode == 5)
		map->green += 1;
	else if (keycode == 11)
		map->blue += 1;
	else if (keycode == 49)
		key_julia(&map->julia);
	mult(map);
	return (0);
}

int		mouse_move(int keycode, int x, int y, t_mass *map)
{
	x = 0;
	y = 0;
	if (keycode == 4)
	{
		mlx_clear_window(map->mlx, map->wind);
		map->zoom *= 1.1;
		mult(map);
	}
	else if (keycode == 5)
	{
		mlx_clear_window(map->mlx, map->wind);
		map->zoom *= 0.9;
		mult(map);
	}
	return (0);
}

int		julia_move(int x, int y, t_mass *map)
{
	ft_printf("%d %d\n", x, y);
	if (map->mark == 1 && map->julia == 1)
	{
		mlx_clear_window(map->mlx, map->wind);
		if (x > 0 && x < map->weight && y > 0 && map->height)
		{
			map->c_im = (y - (WEIGHT) / 2) * 4 / (map->zoom * WEIGHT);
			map->c_re = (x - (WEIGHT) / 2) * 4 / (map->zoom * WEIGHT);
		}
		mult(map);
	}
	return (0);
}
