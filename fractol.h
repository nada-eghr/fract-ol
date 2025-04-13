/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:14:45 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/13 15:39:05 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "MLX42/include/MLX42/MLX42.h"

#define SIZE 800

typedef struct s_fractol {
	double Zx;
	double Zy;
	double Cx;
	double Cy;
	int x;
	int y;
	double zoom;
	double offset_x;
	double offset_y;
	char *name;
	int iteration;
	mlx_t* mlx;
	mlx_image_t *image;
	
}t_fractol;

//--------------------- utils -----------------------
int	ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atoi(char *str);
void init_var(t_fractol *fract);

//-------------------- mandelbrot --------------------
void ft_mandelbrot(t_fractol *fract);


//-------------------- julia -------------------------
void ft_julia(t_fractol *fract);