/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:22:07 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/16 11:11:51 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// void leaks(){
// 	system("leaks fractol");
// }

void	draw_fractals(void *fract)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)fract;
	fractol->x = 0;
	while (fractol->x < SIZE_W)
	{
		fractol->y = 0;
		while (fractol->y < SIZE_H)
		{
			if (ft_strcmp(fractol->name, "mandelbrot") == 0)
				ft_mandelbrot(fract);
			else if (ft_strcmp(fractol->name, "julia") == 0)
				ft_julia(fract);
			else
				ft_error();
			fractol->y++;
		}
		fractol->x++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit_fractal(fract);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fract->offset_x -= 0.2;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fract->offset_x += 0.2;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fract->offset_y -= 0.2;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fract->offset_y += 0.2;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		fract->iteration += 10;
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		fract->iteration -= 10;
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		((void)fract, fract->r += 50, fract->g += 20, fract->b += 20);
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
		init_var(fract);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractal;
	double		zoom_level;

	(void)xdelta;
	fractal = (t_fractol *)param;
	zoom_level = 1.20;
	if (ydelta > 0)
		fractal->zoom = fractal->zoom * zoom_level;
	else if (ydelta < 0)
		fractal->zoom = fractal->zoom / zoom_level;
}

void	ft_check(char **str, t_fractol *fractal)
{
	fractal->cx = ft_atoi(str[2]);
	fractal->cy = ft_atoi(str[3]);
}

int	main(int ac, char **av)
{
	int			i;
	t_fractol	*fract;

	i = 0;
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4
			&& !ft_strcmp(av[1], "julia")))
	{
		fract = malloc(sizeof(t_fractol));
		if (ac == 4)
			ft_check(av, fract);
		fract->name = av[1];
		init_var(fract);
		fract->mlx = mlx_init(SIZE_H, SIZE_W, "fract-ol", true);
		if (!fract->mlx)
			exit(EXIT_FAILURE);
		fract->image = mlx_new_image(fract->mlx, SIZE_W, SIZE_H);
		mlx_image_to_window(fract->mlx, fract->image, 0, 0);
		mlx_key_hook(fract->mlx, &my_keyhook, fract);
		mlx_scroll_hook(fract->mlx, &my_scrollhook, fract);
		mlx_loop_hook(fract->mlx, &draw_fractals, fract);
		mlx_loop(fract->mlx);
		mlx_terminate(fract->mlx);
		exit_fractal(fract);
	}
	ft_error();
}
