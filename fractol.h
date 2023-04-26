/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:41:31 by esteban           #+#    #+#             */
/*   Updated: 2023/04/26 17:36:31 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include "minilibx-linux/mlx.h"

# define WIN_HEIGHT 500
# define WIN_WIDTH 500



typedef struct s_fractol
{
    void	*mlx;
	void	*win;
    double	x;
    double	y;
    double	xmin;
    double	xmax;
    double	ymin;
    double	ymax;
	double	zoom;

}	t_fractol;

void	ft_fractol(int ac, char **av);
void	ft_check(int ac, char **av);
void	ft_innit(t_fractol *fractol);
void	ft_error(int n);


#endif