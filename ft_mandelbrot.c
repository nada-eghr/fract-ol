/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:25:21 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/13 20:39:19 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"


void ft_mandelbrot(t_fractol *fract)
{
	fract->Zx = 0;
	fract->Zy = 0;
	double tmp;

	fract->Cx= ((fract->x / fract->zoom) - fract->offset_x) ;
	fract->Cy= ((fract->y / fract->zoom) - fract->offset_y) ;
	int i = 0;
	fract->iteration = 800;
	while ( ++i < fract->iteration )
	{
		tmp = fract->Zx;
		fract->Zx = (fract->Zx * fract->Zx) - (fract->Zy * fract->Zy) + fract ->Cx;
		fract->Zy = 2 * tmp * fract->Zy + fract->Cy;	
		if (( fract->Zx * fract->Zx) + (fract->Zy * fract->Zy) > 4)
			break;
	}
	if(i == fract->iteration)
		mlx_put_pixel(fract->image, fract->x, fract->y, 0x000000ff);
	else
	{
		uint8_t r = ((float)(0x49) * ((float)i / (fract->iteration / 10)));
		uint8_t g = ((float)(0x2e) * ((float)i / (fract->iteration / 10)));
		uint8_t b = ((float)(0x5e) * ((float)i / (fract->iteration / 10)));
		mlx_put_pixel(fract->image, fract->x, fract->y, r << 24 | g << 16 | b << 8 | 0xff);
	}

}
	
