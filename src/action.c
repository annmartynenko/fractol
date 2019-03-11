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

int	key_press(int keycode, t_mass *map, int x, int y)
{
	mlx_clear_window(map->mlx, map->wind);
	ft_printf("x %d y %d\n", map->moveX, map->moveY);
	if (keycode == 53)
		exit(1);
	if (keycode == 124)
		map->moveX -= 0.1;
	else if (keycode == 123)
		map->moveX += 0.1;
	else if (keycode == 126)
		map->moveY += 0.1;
	else if (keycode == 125)
		map->moveY -= 0.1;
	else if (keycode == 69)
		map->zoom *= 1.1;
	else if (keycode == 78)
		map->zoom *= 0.9;
	ft_printf("x1 %d y1 %d\n", map->moveX, map->moveY);
	choose(map, x, y);
	return (0);
}

int	mouse_move(int keycode,int x, int y, t_mass *map)
{
	x = 0;
	y = 0;
	ft_printf("%d\n", keycode);
	mlx_clear_window(map->mlx, map->wind);
	if (keycode == 4)
		map->zoom *= 1.1;
	else if (keycode == 5)
		map->zoom *= 0.9;
	choose(map, x, y);
	return (0);
}

int	julia_move(int x, int y, t_mass *map)
{
	ft_printf("%d %d\n", x, y);
	mlx_clear_window(map->mlx, map->wind);
	if (map->mark == 1)
	{
		if (x > 0 && x < map->weight && y > 0 && map->height)
		{
			map->cIm = 0.27015 * y / 1000;
			map->cRe = -0.7 * x / 1000;
		}
	}
	choose(map, x, y);
	return (0);
}