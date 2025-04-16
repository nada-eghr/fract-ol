/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:14:45 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/16 11:13:35 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE_H 800
# define SIZE_W 800

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
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
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
void			ft_putendl_fd(char *s, int fd);
//--------------------utils1------------------------
int				exit_fractal(t_fractol *fractal);
void			ft_error(void);

//--------------------utils2 ------------------------
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			f_error(char *msg);
double			ft_atoi(char *s);

//-------------------- mandelbrot --------------------
void			ft_mandelbrot(t_fractol *fract);

//-------------------- julia -------------------------
void			ft_julia(t_fractol *fract);

//--------------main--------------------
void			draw_fractals(void *fract);
void			my_scrollhook(double xdelta, double ydelta, void *param);

#endif