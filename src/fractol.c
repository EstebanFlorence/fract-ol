/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:13:08 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/10 19:42:23 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_matrix(t_fractol *fractol)
{
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
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->ptr, 0, 0);
}

void	ft_fractol(t_fractol *fractol)
{
	if (fractol->fractal == 1)
		ft_mandelbrot(fractol);
	else if (fractol->fractal == 2)
		ft_julia(fractol);
	else if (fractol->fractal == 3)
		ft_yarr(fractol);
/* 	else if (fractol->fractal == 4)
		ft_isaac(fractol); */
}

void	ft_mlxinnit(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!(fractol->mlx))
		ft_error(2);
	fractol->win = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT, "Work in progress");
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
	//ft_mlxplay(fractol);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.img = malloc(sizeof(t_image));
	ft_check(ac, av, &fractol);
	ft_mlxinnit(&fractol);
	ft_structinnit(&fractol);
	ft_matrix(&fractol);
	ft_mlxhooks(&fractol);

	free(fractol.img);
	return (0);
}


/* int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, 1000, 700, "Ciao");
	mlx_key_hook(fractol.win, key_hook, &fractol);
	mlx_loop(fractol.mlx);

	return (0);
} */
