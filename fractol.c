/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:13:08 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/26 00:30:36 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol(int ac, char **av)
{
	if (!ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])))
		ft_mandelbrot();
	else if (!ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
		ft_julia();
	else if (!ft_strncmp(av[1], "Burningship", ft_strlen(av[1])))
		ft_burningship();
}

void	ft_check(int ac, char **av)
{
	if (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])) || \
		ft_strncmp(av[1], "Julia", ft_strlen(av[1])) || \
		ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
		ft_error(0);


}

void	ft_innit(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error(0);
	ft_check(ac, av);
	ft_innit();

	return (0);
}
