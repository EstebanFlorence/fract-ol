/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:14:27 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/16 01:46:20 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractol *fractol)
{
	double	tmpx;

	ft_coordinates(fractol);
	fractol->iter = 0;
	while ((fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4) \
			&& fractol->iter < MAX_ITER)
	{
		tmpx = fractol->zx * fractol->zx - fractol->zy * fractol->zy \
				+ fractol->cx;
		fractol->zy = 2 * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = tmpx;
		fractol->iter++;
	}
	if (fractol->iter < MAX_ITER)
		ft_pixelput(fractol->img, fractol->x, fractol->y, \
					ft_pixelcolor(fractol));
	else
		ft_pixelput(fractol->img, fractol->x, fractol->y, 0x00000000);
}
