/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:16:45 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/19 12:21:26 by adi-nata         ###   ########.fr       */
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
		ft_printf("\nbetween -2.000 and 2.000\n");
		ft_printf("\nType two values separated by a space:\n");
		ft_printf("Examples:\n\t> ./fractol Julia 0.29 0\n\t");
		ft_printf(">\t\t  0 -0.700\n\t>\t\t  -1.476 0\n\n");
		exit(EXIT_SUCCESS);
	}
	if (n == 2)
		perror("mlx error");
	if (n == 3)
		perror("hook error");
	if (n == 4)
		perror("color setting");
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
	ft_freecolors(fractol);
	exit (EXIT_SUCCESS);
	return (0);
}

void	ft_destroy(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img->ptr);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->img);
	free(fractol->mlx);
	ft_freecolors(fractol);
}
