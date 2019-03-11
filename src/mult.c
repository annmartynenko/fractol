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

void	*drawing(void *map)
{
	int x;
	int y;
	int yy;
	t_read	*p;

	p = (t_read*)map;
	yy = HEIGHT / PTHREAD * (p->n + 1);
	y = HEIGHT / PTHREAD * p->n ;
	x = -1;
	while (++y < yy)
	{
		x = -1;
		while (++x < WEIGHT)
		{
			choose(p->mas, x, y);
		}
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
		it->n = i;
		it->mas = map;
		pthread_create(&it[i].way, NULL, &drawing, &it[i]);
	}
	i = -1;
	while (++i < PTHREAD)
		pthread_join(it[i].way, NULL);
	mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
}