/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:26:04 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/02 15:26:08 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	exit_x()
{
	ft_printf("\033[1;32m");
	ft_printf("Usage: ./fractol [name of fractol]\n");
	ft_printf("Name variants:\n");
	ft_printf("- julia\n- mandelbrot\n");
	ft_printf("\033[0m");
	exit(1);
}

t_calc create_calc()
{
	t_calc a;

	a.max_iter = 300;
	a.newRe = a.newIm = a.oldIm = a.oldRe = 0;
	a.pr = 0;
	a.pi = 0;
	return(a);
}

void	choose(t_mass *map)
{
	if (map->mark == 1)
		julia(map);
	else if (map->mark == 2)
		mandelbrot(map);
	mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
}

void	find_name(t_mass *map, char **av)
{
	if (!ft_strcmp(av[1], "julia"))
		map->mark = 1;
	else if (!ft_strcmp(av[1], "mandelbrot"))
		map->mark = 2;
//	else
//		exit_x();
}

//void	create_map(t_mass *map)
//{
//	map->a = create_calc();
//	map->weight = 1300;
//	map->height = 900;
//	map->endian = 0;
//	map->bpp = 32;
//	map->size_line = map->weight;
//	map->zoom = 1;
//	map->moveX = -0.5;
//	map->moveY = 0;
//	map->cRe = -0.7;
//	map->cIm = 0.27015;
//	map->mlx = mlx_init();
//	map->wind = mlx_new_window(map->mlx, map->weight, map->height, "Fractol");
//	map->img = mlx_new_image(map->mlx, map->weight, map->height);
//	map->image = (int *)mlx_get_data_addr(map->img, &map->bpp, &map->size_line, &map->endian);
//	choose(map);
//	mlx_hook(map->wind, 2, 0, key_press, &map);
//	mlx_mouse_hook(map->wind, mouse_move, &map);
//	mlx_hook(map->wind, 6, 0, julia_move, &map);
//	mlx_hook(map->wind, 17, 0, exit_x, &map);
//	mlx_loop(map->mlx);
//}

int main(int ac, char **av)
{
	t_mass map;

	if (ac > 1)
		find_name(&map, av);
	else
		exit_x();
	map.a = create_calc();
	map.weight = 1300;
	map.height = 900;
	map.endian = 0;
	map.bpp = 32;
	map.size_line = map.weight;
	map.zoom = 1;
	map.moveX = -0.5;
	map.moveY = 0;
	map.cRe = -0.7;
	map.cIm = 0.27015;
	map.mlx = mlx_init();
	map.wind = mlx_new_window(map.mlx, map.weight, map.height, "Fractol");
	map.img = mlx_new_image(map.mlx, map.weight, map.height);
	map.image = (int *)mlx_get_data_addr(map.img, &map.bpp, &map.size_line, &map.endian);
	choose(&map);
	mlx_hook(map.wind, 2, 0, key_press, &map);
	mlx_mouse_hook(map.wind, mouse_move, &map);
	mlx_hook(map.wind, 6, 0, julia_move, &map);
	mlx_hook(map.wind, 17, 0, exit_x, &map);
	mlx_loop(map.mlx);
//	create_map(&map);
	return(0);
}