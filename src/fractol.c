/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:13:08 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/16 01:20:21 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_rendering(t_fractol *fractol)
{
	fractol->y = 0;
	while (fractol->y < WIN_HEIGHT)
	{
		fractol->x = 0;
		while (fractol->x < WIN_WIDTH)
		{
			ft_fractol(fractol);
			fractol->x++;
		}
		fractol->y++;
	}
	mlx_put_image_to_window(fractol->mlx, \
		fractol->win, fractol->img->ptr, 0, 0);
}

void	ft_fractol(t_fractol *fractol)
{
	if (fractol->fractal == 1)
		ft_mandelbrot(fractol);
	else if (fractol->fractal == 2)
		ft_julia(fractol);
	else if (fractol->fractal == 3)
		ft_yarrr(fractol);
/* 	else if (fractol->fractal == 4)
		ft_isaac(fractol); */
}

void	ft_mlxinnit(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!(fractol->mlx))
		ft_error(2);
	fractol->win = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT, \
									"Fract-ol");
	if (!(fractol->win))
		ft_error(2);
	fractol->img->ptr = mlx_new_image(fractol->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!(fractol->img))
		ft_error(2);
	fractol->img->data = mlx_get_data_addr(fractol->img->ptr, \
						&fractol->img->bitsxpixel, \
						&fractol->img->size_line, \
						&fractol->img->endian);
	if (!(fractol->img->data))
		ft_error(2);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.img = malloc(sizeof(t_image));
	ft_check(ac, av, &fractol);
	ft_mlxinnit(&fractol);
	ft_structinnit(&fractol);
	ft_rendering(&fractol);
	ft_mlxhooks(&fractol);
	ft_destroy(&fractol);
	return (0);
}
