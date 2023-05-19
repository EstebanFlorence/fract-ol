/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinnit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:41:32 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/19 12:00:05 by adi-nata         ###   ########.fr       */
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
	fractol->fractal = 2;
}

void	ft_check(int ac, char **av, t_fractol *fractol)
{
	if (!ft_strncmp(av[1], "Mandelbrot", 11) && ac == 2)
		fractol->fractal = 1;
	else if (!ft_strncmp(av[1], "Julia", 6))
		ft_checkjulia(ac, av, fractol);
	else if (!ft_strncmp(av[1], "Burningship", 12))
		fractol->fractal = 3;
	else if (!ft_strncmp(av[1], "Newton", 7))
		fractol->fractal = 4;
	else
		ft_error(0);
}

void	ft_innit(t_fractol *fractol)
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
	fractol->img_shift = 1.1;
	fractol->color_iter = 0;
	color_set(fractol);
}
