/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:16:45 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/11 16:42:34 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int n)
{
	if (n == 0)
	{
		ft_printf("\nusage: ./fractol <fractal>\n\nFractals available:\n");
		ft_printf("> Mandelbrot\n> Julia\n> Burningship\n\n");
		exit(EXIT_SUCCESS);
	}
	if (n == 1)
	{
		ft_printf("\nusage: ./fractol Julia <c_real> <c_imaginary>\n");
		ft_printf("\n<c_real> + <c_imaginary> = complex number");
		ft_printf("\nbetween -2.000 and 2.000");
		ft_printf("\nPlease type two values separated by a space:\n");
		ft_printf("\nExamples:\n\t> ./fractol Julia 0.123 0.321\n\t");
		ft_printf("> ./fractol Julia 0 -0.700");
		exit(EXIT_SUCCESS);
	}
	if (n == 2)
		perror("mlx error");
	if (n == 3)
		perror("hook error");
	exit(EXIT_FAILURE);
}

void	ft_coordinates(t_fractol *fractol)
{
	if (fractol->fractal == 1 || fractol->fractal == 3)
	{
		fractol->cx = fractol->x / fractol->zoom + fractol->x_min;
		fractol->cy = fractol->y / fractol->zoom + fractol->y_min;
		fractol->zx = 0;
		fractol->zy = 0;
	}
	if (fractol->fractal == 2)
	{
		fractol->zx = fractol->x / fractol->zoom + fractol->x_min;
		fractol->zy = fractol->y / fractol->zoom + fractol->y_min;
	}
}

int	color(int iter)
{
	unsigned int	color;

	color = 0xFF66B0F0;
	color += (iter * 255 / MAX_ITER) << 16;
	color += (iter * 255 / MAX_ITER) << 8;
	color += (iter * 255 / MAX_ITER);
	return (color);
}

void	ft_pixelput(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bitsxpixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img->ptr);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->img);
	free(fractol->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}
