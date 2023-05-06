/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:16:45 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/06 18:17:16 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int n)
{
	if (n == 0)
	{
		ft_printf("usage: ./fractol <fractal>\n\nFractals available:\n");
		ft_printf("> Mandelbrot\n> Julia\n> Burningship\n\n");
		exit(EXIT_SUCCESS);
	}
    if (n == 1)
		perror("mlx() error");
	exit(EXIT_FAILURE);
}

int	key_hook(int key, t_fractol *fractol)
{
	ft_printf("KEY HOOK!\n");
	return (0);
}

void	ft_julia()
{
	ft_printf("Julia\n");
}

void	ft_yarrr()
{
	ft_printf("Burning Ship\n");
}

void	ft_mlxplay(t_fractol *fractol)
{
	while (fractol->x < WIN_WIDTH)
	{
		my_mlx_pixel_put(fractol->img, fractol->x, fractol->y, 0x000FF0FF);
		fractol->x++;
	}
}
