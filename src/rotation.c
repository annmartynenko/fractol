/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:21:04 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/09 16:21:06 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdio.h>

void	rotation_x(t_mass *map, int mark, double angle)
{
	double	pr_z;
	double	pr_y;
	int		i;
	int		j;

	midpoint(map, mark);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			pr_z = map->coord[i][j].z;
			pr_y = map->coord[i][j].y;
			map->coord[i][j].y = pr_y * cos(angle) + pr_z * sin(angle);
			map->coord[i][j].z = -pr_y * sin(angle) + pr_z * cos(angle);
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}

void	rotation_y(t_mass *map, int mark, double angle)
{
	double	pr_x;
	double	pr_z;
	int		i;
	int		j;

	midpoint(map, mark);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			pr_x = map->coord[i][j].x;
			pr_z = map->coord[i][j].z;
			map->coord[i][j].x = pr_x * cos(angle) + pr_z * sin(angle);
			map->coord[i][j].z = -pr_x * sin(angle) + pr_z * cos(angle);
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}

void	rotation_z(t_mass *map, int mark, double angle)
{
	double	pr_x;
	double	pr_y;
	int		i;
	int		j;

	midpoint(map, mark);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			pr_x = map->coord[i][j].x;
			pr_y = map->coord[i][j].y;
			map->coord[i][j].x = pr_x * cos(angle) - pr_y * sin(angle);
			map->coord[i][j].y = pr_x * sin(angle) + pr_y * cos(angle);
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}

void	move_z(t_mass *map, int keycode)
{
	if (keycode == 115)
	{
		map->angle[2] = -0.1;
		rotation_z(map, 3, map->angle[2]);
	}
	else if (keycode == 119)
	{
		map->angle[2] = 0.1;
		rotation_z(map, 3, map->angle[2]);
	}
	mlx_clear_window(map->mlx, map->wind);
	draw(map);
}

void	move_xy(t_mass *map, int keycode)
{
	if (keycode == 125)
	{
		map->angle[0] = -0.1;
		rotation_x(map, 3, map->angle[0]);
	}
	else if (keycode == 126)
	{
		map->angle[0] = 0.1;
		rotation_x(map, 3, map->angle[0]);
	}
	else if (keycode == 123)
	{
		map->angle[1] = -0.1;
		rotation_y(map, 3, map->angle[1]);
	}
	else if (keycode == 124)
	{
		map->angle[1] = 0.1;
		rotation_y(map, 3, map->angle[1]);
	}
	mlx_clear_window(map->mlx, map->wind);
	draw(map);
}
