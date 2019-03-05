/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:15:52 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/04 15:15:53 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	small_big(t_mass *map, int mark)
{
	int i;
	int j;

	midpoint(map, mark);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			map->coord[i][j].x *= map->koef;
			map->coord[i][j].y *= map->koef;
			map->coord[i][j].z *= map->koef;
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}

void	zoom(t_mass *map, int keycode)
{
	if (keycode == 69)
	{
		map->koef = 1.1;
		small_big(map, 3);
		mlx_clear_window(map->mlx, map->wind);
		draw(map);
	}
	else if (keycode == 78)
	{
		map->koef = 0.9;
		small_big(map, 3);
		mlx_clear_window(map->mlx, map->wind);
		draw(map);
	}
}

void	marks(t_mass *map, int i, int j, int mark)
{
	if (mark == 1)
	{
		map->coord[i][j].x = map->coord[i][j].x - (map->weight * 40) / 2;
		map->coord[i][j].y = map->coord[i][j].y - (map->height * 40) / 2;
	}
	else if (mark == 2)
	{
		map->coord[i][j].x = map->coord[i][j].x + 1500 / 2 + map->center[0];
		map->coord[i][j].y = map->coord[i][j].y + 1200 / 2 + map->center[1];
	}
	else if (mark == 3)
	{
		map->coord[i][j].x = map->coord[i][j].x - 1500 / 2 - map->center[0];
		map->coord[i][j].y = map->coord[i][j].y - 1200 / 2 - map->center[1];
	}
}

void	midpoint(t_mass *map, int mark)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			marks(map, i, j, mark);
			j++;
		}
		i++;
	}
}

void	up_down(t_mass *map, int plus)
{
	double	pr_y;
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			pr_y = map->coord[i][j].y;
			map->coord[i][j].y = pr_y + plus;
			j++;
		}
		i++;
	}
}

void	left_right(t_mass *map, int plus)
{
	double	pr_x;
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			pr_x = map->coord[i][j].x;
			map->coord[i][j].x = pr_x + plus;
			j++;
		}
		i++;
	}
}

void	move(t_mass *map, int keycode)
{
	if (keycode == 1)
	{
		map->center[1] += 10;
		up_down(map, 10);
	}
	else if (keycode == 13)
	{
		map->center[1] += -10;
		up_down(map, -10);
	}
	else if (keycode == 0)
	{
		map->center[0] += -10;
		left_right(map, -10);
	}
	else if (keycode == 2)
	{
		map->center[0] += 10;
		left_right(map, 10);
	}
	mlx_clear_window(map->mlx, map->wind);
	draw(map);
}
