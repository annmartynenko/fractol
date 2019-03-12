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
# define PTHREAD 8
# define HEIGHT 900
# define WEIGHT 1300

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
}				t_mass;

typedef struct	s_read
{
	int			n;
	t_mass		*mas;
	pthread_t	way;
}				t_read;

void	mandelbrot(t_mass *map, int x, int y);
void	julia(t_mass *map, int x, int y);
int		key_press(int keycode, t_mass *map);
int		mouse_move(int keycode,int x, int y, t_mass *map);
void	find_name(t_mass *map, char **av);
int		julia_move(int x, int y, t_mass *map);
void	choose(t_mass *map, int x, int y);
void	mult(t_mass *map);
void	heart(t_mass *map, int x, int y);

#endif