/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:26:20 by amartyne          #+#    #+#             */
/*   Updated: 2019/03/02 15:26:21 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include "../src/libft/libft.h"
# include <pthread.h>

typedef struct	s_calc
{
	double	pr;
	double	pi;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	int		max_iter;
}				t_calc;

typedef struct	s_mass
{
	int		height;
	int		weight;
	void	*wind;
	void	*mlx;
	void	*img;
	int 	*image;
	int		bpp;
	int		size_line;
	int		endian;
	int 	mark;
	double	zoom;
	double	moveX;
	double	moveY;
	double	cRe;
	double 	cIm;
	t_calc	a;
}				t_mass;

void	mandelbrot(t_mass *map);
void	julia(t_mass *map);
int		key_press(int keycode, t_mass *map);
int		mouse_move(int keycode,int x, int y, t_mass *map);
void	find_name(t_mass *map, char **av);
int		julia_move(int x, int y, t_mass *map);
void	choose(t_mass *map);
t_calc	create_calc();
int		julia_move(int x, int y, t_mass *map);

#endif