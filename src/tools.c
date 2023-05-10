/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:16:45 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/10 19:30:47 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_checkjulia(int ac, char **av, t_fractol *fractol)
{
	if (ac != 4)
		ft_error(1);
	fractol->cx = ft_atof(av[2]);
	fractol->cy = ft_atof(av[3]);
	if (fractol->cx < -2 || fractol->cx > 2 || \
		fractol->cy < -2 || fractol->cy > 2)
		ft_error(1);
}

void	ft_check(int ac, char **av, t_fractol *fractol)
{
	if (!ft_strncmp(av[1], "Mandelbrot", 11) && ac == 2)
	fractol->fractal = 1;
	else if	(!ft_strncmp(av[1], "Julia", 6))
	fractol->fractal = 2;
	else if	(!ft_strncmp(av[1], "Burningship", 12))
	fractol->fractal = 3;
	else if	(!ft_strncmp(av[1], "Newton", 7))
	fractol->fractal = 4;
	else
		ft_error(0);
	if (fractol->fractal == 2)
		ft_checkjulia(ac, av, fractol);
}

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
		ft_printf("\n<c_real> + <c_imaginary> = complex number between -2.000 and 2.000");
		ft_printf("\n\nInstructions for <c_real> <c_imaginary>:\n");
		ft_printf("\nPlease type two values separated by a space:\n");
		ft_printf("\nExamples:\n\t> ./fractol Julia 0.123 0.321\n\t");
		ft_printf("> ./fractol Julia 0 -0.700\n\t> ./fractol Julia -0.230 0.089\n");
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

//	In the get_color function, (iter * 255 / MAX_ITER) << 16 means 
//	that the binary representation of (iter * 255 / MAX_ITER) 
//	is shifted 16 bits to the left. The result is a color value 
//	where the first 8 bits (from the left) represent the red component,
//	the second 8 bits represent the green component, and 
//	the last 8 bits represent the blue component.

int	color(int iter)
{
	unsigned int	color;

	color = 0xFF66B0F0;
	color += (iter * 255 / MAX_ITER) << 16;
	color += (iter * 255 / MAX_ITER) << 8;
	color += (iter * 255 / MAX_ITER);
	return (color);
}


//	Colora un singolo pixel. NB: img->data

void	ft_pixelput(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bitsxpixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_structinnit(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->x_min = -2.0;
	fractol->x_max = 2.0;
	fractol->y = 0;
	fractol->y_min = -2.0;
	fractol->y_max = 2.0;
	fractol->iter = 0;
	fractol->max_iter = MAX_ITER;
	fractol->zoom = MAX_ITER;

}


void	ft_mlxplay(t_fractol *fractol)
{
	while (fractol->x < WIN_WIDTH)
	{
		ft_pixelput(fractol->img, fractol->x, fractol->y, 0x000FF0FF);
		fractol->x++;
	}
}
