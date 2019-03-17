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

int		exit_x(void)
{
	ft_printf("\033[1;32m");
	ft_printf("Usage: ./fractol [name of fractol]\n");
	ft_printf("Name variants:\n");
	ft_printf("- julia\n- mandelbrot\n- flower\n- celtic\n- ship\n");
	ft_printf("- tricorn\n- heart\n- buffalo\n");
	ft_printf("\033[0m");
	exit(1);
}

void	choose(t_mass *map, int x, int y)
{
	if (map->mark == 1)
		julia(map, x, y);
	else if (map->mark == 2)
		mandelbrot(map, x, y);
	else if (map->mark == 3)
		flower(map, x, y);
	else if (map->mark == 4)
		celtic(map, x, y);
	else if (map->mark == 5)
		ship(map, x, y);
	else if (map->mark == 6)
		tricorn(map, x, y);
	else if (map->mark == 7)
		heart(map, x, y);
	else if (map->mark == 8)
		buffalo(map, x, y);
}

void	find_name(t_mass *map, char **av)
{
	if (!ft_strcmp(av[1], "julia"))
		map->mark = 1;
	else if (!ft_strcmp(av[1], "mandelbrot"))
		map->mark = 2;
	else if (!ft_strcmp(av[1], "flower"))
		map->mark = 3;
	else if (!ft_strcmp(av[1], "celtic"))
		map->mark = 4;
	else if (!ft_strcmp(av[1], "ship"))
		map->mark = 5;
	else if (!ft_strcmp(av[1], "tricorn"))
		map->mark = 6;
	else if (!ft_strcmp(av[1], "heart"))
		map->mark = 7;
	else if (!ft_strcmp(av[1], "buffalo"))
		map->mark = 8;
	else
		exit_x();
}

void	create_map(t_mass *map)
{
	map->weight = WEIGHT;
	map->height = HEIGHT;
	map->endian = 0;
	map->bpp = 32;
	map->size_line = map->weight;
	map->zoom = 0.7;
	map->move_x = -0.5;
	map->move_y = 0;
	map->c_re = -0.7;
	map->c_im = 0.27015;
	map->red = 2;
	map->blue = 0;
	map->green = 10;
	map->julia = 1;
	map->max_iter = MAX_ITER;
	map->mlx = mlx_init();
	map->wind = mlx_new_window(map->mlx, map->weight, map->height, "Fractol");
	map->img = mlx_new_image(map->mlx, map->weight, map->height);
	map->image = mlx_get_data_addr(map->img, &map->bpp,\
	&map->size_line, &map->endian);
}

int		main(int ac, char **av)
{
	t_mass map;

	if (ac == 2)
		find_name(&map, av);
	else
		exit_x();
	create_map(&map);
	mult(&map);
	print_action(&map);
	mlx_hook(map.wind, 2, 0, key_press, &map);
	mlx_mouse_hook(map.wind, mouse_move, &map);
	mlx_hook(map.wind, 6, 0, julia_move, &map);
	mlx_hook(map.wind, 17, 0, exit_x, &map);
	mlx_loop(map.mlx);
	return (0);
}
