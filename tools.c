/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:16:45 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/06 23:31:07 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_check(int ac, char **av, t_fractol *fractol)
{
	if (ac != 2)
		ft_error(0);
	if (ft_strncmp(av[1], "Mandelbrot", 11) && \
		ft_strncmp(av[1], "Julia", 6) && \
		ft_strncmp(av[1], "Burningship", 12))
		ft_error(0);
	fractol->fractal = av[1];

}

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

void	ft_coordinates(t_fractol *fractol)
{
	fractol->cx = fractol->x / fractol->zoom + fractol->x_min;
	fractol->cy = fractol->y / fractol->zoom + fractol->y_min;
	fractol->zx = 0;
	fractol->zy = 0;
}

void	color(int iter)
{

}


//	Colora un singolo pixel. NB: img->data
void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bitsxpixel / 8));
	*(unsigned int*)dst = color;
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
