/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:45:49 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/11 19:45:50 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	print_action(t_mass *map)
{
	mlx_string_put(map->mlx, map->wind, 10, 5,\
	0xf5978a, "zoom: +/- or 'mouse'");
	mlx_string_put(map->mlx, map->wind, 10, 25, 0xf5978a, "color: r, g, b");
	mlx_string_put(map->mlx, map->wind, 10, 45, 0xf5978a, "move: arrows");
	mlx_string_put(map->mlx, map->wind, 10, 65,\
	0xf5978a, "pause in julia: space");
	mlx_string_put(map->mlx, map->wind, 10, 85, 0xf5978a, "change fractal:");
	mlx_string_put(map->mlx, map->wind, 10, 105,\
	0xf5978a, "1-julia, 2-mandelbrot");
	mlx_string_put(map->mlx, map->wind, 10, 125,\
	0xf5978a, "3-flower, 4-celtic");
	mlx_string_put(map->mlx, map->wind, 10, 145,\
	0xf5978a, "5-ship, 6-tricorn");
	mlx_string_put(map->mlx, map->wind, 10, 165,\
	0xf5978a, "7-heart, 8-buffalo");
}

void	get_color(int x, int y, t_mass *map, int it)
{
	double	k;
	int		i;

	i = y * map->size_line + x * 4;
	k = it * log(2);
	if (it == map->max_iter)
	{
		map->image[i] = (char)0;
		map->image[++i] = (char)0;
		map->image[++i] = (char)0;
		map->image[++i] = (char)0;
	}
	else
	{
		map->image[i] = (char)(map->blue * k);
		map->image[++i] = (char)(map->green * k);
		map->image[++i] = (char)(map->red * k);
	}
}

void	*drawing(void *map)
{
	int		x;
	int		y;
	int		yy;
	t_read	*p;

	p = (t_read*)map;
	yy = (HEIGHT * (p->n + 1) / PTHREAD);
	y = (HEIGHT * (p->n) / PTHREAD) - 1;
	while (++y < yy)
	{
		x = -1;
		while (++x < WEIGHT)
			choose(p->mas, x, y);
	}
	return (0);
}

void	mult(t_mass *map)
{
	t_read	*it;
	int		i;

	i = -1;
	it = (t_read*)malloc(sizeof(t_read) * PTHREAD);
	while (++i < PTHREAD)
	{
		it[i].n = i;
		it[i].mas = map;
		pthread_create(&it[i].way, NULL, drawing, &it[i]);
	}
	i = -1;
	while (++i < PTHREAD)
		pthread_join(it[i].way, NULL);
	mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
	print_action(map);
	free(it);
}
