/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:22:07 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/13 15:38:39 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void draw_fractals(void *fract)
{
	t_fractol *fractol;

	fractol = (t_fractol *)fract;
	fractol->x = 0;
	while( fractol->x < SIZE)
	{
		fractol->y = 0;
		while( fractol->y <  SIZE)
		{
			
			mlx_put_pixel(fractol->image, fractol->x, fractol->y, 0x4484bd);
			if (ft_strncmp(fractol->name , "mandelbrot", 10) == 0)
			{
				ft_mandelbrot(fract);
			}
			else if (ft_strncmp(fractol->name , "julia", 5) == 0)
			{
				ft_julia(fract);
			}
			else 
				exit(1);
			
			// mandelbrot
			
			// julia
			(fractol->y)++;
		}
		(fractol->x)++;
	}
}
	

	
	// while ( x < 400 && y >= 150)
	// {
	// 	mlx_put_pixel(fractol->image, x, y, 0xFF00F0);
	// 	x++;
	// 	y--;
	// }
		// 	int y = 320;
		// 	while( y>= 200)
		// 	{
		// 		mlx_put_pixel(fractol->image, 250, 250, 0xFF00F0);
		// 		y--;
		// 	}
		// x++;	
		// }

		// mlx_put_pixel(fractol->image, 250, 250, 0xFF00F0);
		// mlx_put_pixel(fractol->image, 420, 100, 0xFF00F0);
	
	// int x = 0 ;
	// while ( x < 250)
	// {
		
		
	// 	mlx_put_pixel(fractol->image, x, 250, 0xFF00F0);
	// 	x++;
		
	// }
	//  x = 0 ;
	// while ( x < 250)
	// {
		
	// 	mlx_put_pixel(fractol->image, x, 251, 0xFF00F0);
	// 	x++;
		
	// }
	



// void ft_put_pixel(t_fractol *fractol, int x, int y, int color)
// {	
// 	 x = 0;
// 	while ( x < 250)
// 	{
// 		y = 0;
// 		while ( y < 2)
// 		{
// 			mlx_put_pixel(fractol->image, x, y, 0xFF00F0);
// 			y++;
// 		}
// 		x++;
// 	}
		
	


	
	// while ( y <= 250)
	// {
	// 	int  x = 0;
	// 	while ( x <= 250)
	// 	{
	// 		mlx_put_pixel(fractol->image, x, y, 0xFF00F0);
	// 		x++;
	// 	}
	// 	y++;
	 	
		
	// }
	
		
	
	
		
	// }
int main(int ac , char **av)
{
	int i = 0;
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		t_fractol *fract;
		fract = malloc(sizeof(t_fractol));
		
		if ( ac == 4 )
		{
			fract->Cx = ft_atoi(av[2]);
			fract->Cy = ft_atoi(av[3]);
		}
		fract->name = av[1];
		init_var(fract);
		fract->mlx = mlx_init(SIZE,SIZE, "fract-ol", false);
		fract->image = mlx_new_image(fract ->mlx ,SIZE, SIZE);
		mlx_image_to_window(fract->mlx, fract->image, 0, 0);
		mlx_loop_hook(fract->mlx, draw_fractals, fract);
		mlx_loop(fract->mlx);
		
		
	}
	else
		exit(1);
	
}


// // -----------------------------------------------------------------------------
// // Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// // See README in the root project for more information.
// // -----------------------------------------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "MLX42/include/MLX42/MLX42.h"

// #define WIDTH 512
// #define HEIGHT 512

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
