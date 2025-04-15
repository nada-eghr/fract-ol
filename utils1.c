/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:22:32 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/15 18:10:44 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_fractol *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->image);
	mlx_close_window(fractal->mlx);
	free(fractal);
	exit(0);
	return (0);
}

void	ft_error(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal>", 1);
	ft_putendl_fd("Available fractals: mandelbrot, julia", 1);
	exit(1);
}
