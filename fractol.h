/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:14:45 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/15 12:01:02 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE_H 800
#define SIZE_W 800

typedef struct s_fractol
{
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	int			x;
	int			y;
	int			i;
	int			j;
	int			color;
	int			color_2;
	double		zoom;
	double		offset_x;
	double		offset_y;
	char		*name;
	int			iteration;
	mlx_t		*mlx;
	mlx_image_t	*image;

}				t_fractol;

//--------------------- utils -----------------------
void			init_var(t_fractol *fract);
int				get_rgba(int r, int g, int b, int a);
int				get_rg_l(int r, int g, int b, t_fractol *fract);
int				get_rg_julia(int r, int g, int b, t_fractol *fract);

//--------------------utils2 ------------------------
int 			ft_strlen(char *str);
double			ft_atoi(char *s);
int				ft_strcmp(char *s1, char *s2);

//-------------------- mandelbrot --------------------
void			ft_mandelbrot(t_fractol *fract);

//-------------------- julia -------------------------
void			ft_julia(t_fractol *fract);

//--------------main--------------------
void	ft_error(void);
void	ft_putendl_fd(char *s, int fd);
int	exit_fractal(t_fractol *fractal);
void	draw_fractals(void *fract);
void	my_scrollhook(double xdelta, double ydelta, void *param);