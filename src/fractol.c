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
	exit(1);
}

int	key_press(int keycode)
{
	ft_printf("%d\n", keycode);
	if (keycode == 53)
		exit(1);
	return (0);
}

int	mouse_move(int keycode)
{
	ft_printf("%d\n", keycode);
	if (keycode == 4)
		ft_printf("scroll up\n");
	else if (keycode == 5)
		ft_printf("scroll down\n");
	return (0);
}
void	find_name(t_mass *map, char **av)
{
	if (!ft_strcmp(av[1], "julia"))
		map->mark = 1;
	else if (!ft_strcmp(av[1], "mandelbrot"))
		map->mark = 2;
}

void	choose(t_mass *map)
{
	if (map->mark == 1)
		julia(map);
	else if (map->mark == 2)
		mandelbrot(map);
}

int main(int ac, char **av)
{
	t_mass map;

	if (ac > 1)
		find_name(&map, av);
	else
		exit(1);
	map.weight = 1500;
	map.height = 1000;
	map.endian = 0;
	map.bpp = 32;
	map.size_line = 1500;
	map.mlx = mlx_init();
	map.wind = mlx_new_window(map.mlx, map.weight, map.weight, "Fractol");
	map.img = mlx_new_image(map.mlx, map.weight, map.weight);
	map.image = (int *)mlx_get_data_addr(map.img, &map.bpp, &map.size_line, &map.endian);
	choose(&map);
	mlx_put_image_to_window(map.mlx, map.wind, map.img, 0, 0);
	mlx_hook(map.wind, 2, 0, key_press, &map);
	mlx_hook(map.wind, 6, 0, mouse_move, &map);
	mlx_hook(map.wind, 17, 0, exit_x, &map);
	mlx_loop(map.mlx);
	return(0);
}