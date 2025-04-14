/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:36:43 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/13 20:51:22 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"
void ft_julia(t_fractol *fract)
{
	// fract->Zx = 0;
	// fract->Zy = 0;
	double tmp;

	fract->Zx= ((fract->x / fract->zoom) - fract->offset_x) ;
	fract->Zy= ((fract->y / fract->zoom) - fract->offset_y) ;
	int i = 0;
	fract->iteration = 100;
	while ( ++i < fract->iteration )
	{
		tmp = fract->Zx;
		fract->Zx = (fract->Zx * fract->Zx) - (fract->Zy * fract->Zy) + fract ->Cx;
		fract->Zy = 2 * tmp * fract->Zy + fract->Cy;	
		if (( fract->Zx * fract->Zx) + (fract->Zy * fract->Zy) > 4)
			break;
	}
	if(i == fract->iteration)
	{
		uint8_t r = (0x05);
		uint8_t g = (0x01) ;
		uint8_t b = (0x01) ;
		mlx_put_pixel(fract->image, fract->x, fract->y,  r << 24 | g << 16 | b << 8 | 0xff);
	}
		
	else{
		uint8_t r = ((float)(0x72) * ((float)i / (fract->iteration / 10)));
		uint8_t g = ((float)(0xb5) * ((float)i / (fract->iteration / 10)));
		uint8_t b = ((float)(0x48) * ((float)i / (fract->iteration / 10)));
		mlx_put_pixel(fract->image, fract->x, fract->y, r << 24 | g << 16 | b << 8 | 0xff);
	}
}