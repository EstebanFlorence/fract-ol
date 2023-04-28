/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:16:45 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/29 00:15:35 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int n)
{
	if (n == 0)
	{
		ft_printf("usage: ./fractol <fractal>\nFractals available:\n");
		ft_printf("> Mandelbrot\n> Julia\n> Burningship\n");
		exit(0);
	}
    if (n == 1)
		perror("mlx() error");
	exit(EXIT_FAILURE);
}

void	ft_mandelbrot()
{
	ft_printf("Mandelbrot\n");
}

void	ft_julia()
{
	ft_printf("Julia\n");
}

void	ft_yarrr()
{
	ft_printf("Burning Ship\n");
}
