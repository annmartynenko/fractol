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

typedef struct	s_xyz
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_xyz;

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
	t_xyz	**coord;
	double	angle[3];
	double	koef;
	double	center[2];
}				t_mass;

typedef struct	s_calc
{
	double pr;
	double pi;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	double zoom;
	double moveX;
	double moveY;
	int max_iter;
}				t_calc;

void	mandelbrot(t_mass *map);
void	julia(t_mass *map);

#endif