/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:13:08 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/25 23:45:27 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_innit(int ac, char **av)
{
    if (!ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1] )))
		ft_mandelbrot();
    else if (!ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
		ft_julia();
    else if (!ft_strncmp(av[1], "Burningship", ft_strlen(av[1])))
        ft_burningship();
    else
        ft_error(0);
}

int	main(int ac, char **av)
{
    if (ac != 2)
        ft_error(0);
    ft_innit(ac, av);

    return (0);
}
